import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist

class control(Node):

    def __init__(self):  
        super().__init__("control_ieee_node")
        self.pub = self.create_publisher(
            Twist,
            "/PID_msg",
            10
        )
        msg = Twist()
        msg.linear.x = 0.6
        msg.linear.y = 0.8
        msg.linear.z = 0.5
        self.pub.publish(msg)

  
def main(args=None):
    rclpy.init(args=args)
    node = control()
    rclpy.shutdown()
  
if __name__ == "__main__":
    main() 