
import rclpy
from rclpy.node import Node
import cv2
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import threading
from std_msgs.msg import String
from pyzbar.pyzbar import decode


class WebcamViewerNode(Node):
    def __init__(self):
        super().__init__('webcam_viewer_node')
        self.publisher = self.create_publisher(Image, 'webcam_image', 10)
        self.bridge = CvBridge()
        self.capture = cv2.VideoCapture(0)  # 0 for the default webcam
        self.display_thread = threading.Thread(target=self.display_video)
        self.display_thread.daemon = True  # Close thread when main program exits
        self.pub = self.create_publisher(String, 'command', 10)

        if not self.capture.isOpened():
            self.get_logger().error('Cannot open webcam')
            return

        self.display_thread.start()
        
        self.last_command = None

    def display_video(self):
        cv2.namedWindow('Webcam Stream', cv2.WINDOW_NORMAL)
        while rclpy.ok():
            ret, frame = self.capture.read()
            if ret:
                img_msg = self.bridge.cv2_to_imgmsg(frame, encoding='bgr8')
                self.publisher.publish(img_msg)
                
                # Decode QR codes from the frame
                decoded_objects = decode(frame)
                qr_msg = String()
                if decoded_objects:
                    for obj in decoded_objects:
                        qr_data = obj.data.decode('utf-8')
                        # You can publish the QR code data as a String message here
                        qr_msg.data = qr_data
                else:
                    qr_msg.data = "No QR code detected"
                if qr_msg.data != self.last_command:
                    self.last_command = qr_msg.data
                    self.pub.publish(qr_msg)
                if qr_msg.data == "No QR code detected":
                    cv2.putText(frame, qr_msg.data, (30,50), cv2.FONT_HERSHEY_SIMPLEX, 1.5, (0, 0, 255), 2)
                else:
                    cv2.putText(frame, qr_msg.data, (30,50), cv2.FONT_HERSHEY_SIMPLEX, 1.5, (0, 255, 0), 2)
                cv2.imshow('Webcam Stream', frame)
                key = cv2.waitKey(1)
                if key == 27:  # Exit on ESC key press
                    break



def main(args=None):
    rclpy.init(args=args)
    node = WebcamViewerNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()
    cv2.destroyAllWindows()

if __name__ == '__main__':
    main()