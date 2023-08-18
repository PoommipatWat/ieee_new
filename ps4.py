import rclpy

from rclpy.node import Node

from sensor_msgs.msg import Joy

from std_msgs.msg import String

from std_msgs.msg import Float64

from geometry_msgs.msg import Twist

from sensor_msgs.msg import Imu

from sensor_msgs.msg import Image

from rclpy import qos

import math
import cv2
import numpy as np
from ahrs.filters import Madgwick
from cv_bridge import CvBridge
import datetime
import time

from simple_pid import PID

from pathlib import Path
import configparser

class Ps4(Node):
	def __init__(self):
		super().__init__("xbox_control_node")
		self.subscription = self.create_subscription(
			Image,
			'/color/image_raw',  # Adjust the topic name as per your setup
			self.image_callback,
			10
		)

		time.sleep(2)

		self.sent_drive = self.create_publisher(Twist, "control_drive_topic", qos_profile=qos.qos_profile_system_default)
		self.sent_drive_timer = self.create_timer(0.05, self.sent_drive_callback)
		
		self.x = 0.0
		self.y = 0.5
		
		self.window_state = 'fullscreen'
		
		self.status_walk = "run"
		self.stop = True
		self.col = (0,255,0)

	def image_callback(self, msg):
		bridge = CvBridge()
		cv_image = bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')
		self.img = cv_image
		self.gui()

	def sent_drive_callback(self): #publisher drive topic
		msg = Twist()
		self.get_logger().info(f"{self.status_walk}")
		x = 0.0
		y = 0.0
		turn = 0.0
		if self.stop:
			if self.status_walk == "run":
				y = 0.5
				x = 0.0
				turn = 0.0
			elif self.status_walk == "Turn Left":
				turn = -0.5
				msg.linear.z = 1.0
			elif self.status_walk == "Turn Right":
				turn = 0.5
				msg.linear.z = 2.0
			elif self.status_walk == "Turn Around":
				msg.linear.z = 3.0
				turn = 0.5
			elif self.status_walk == "Stop":
				self.stop = False	
		else:
			if self.status_walk == "start":
				self.stop = True		
		y *= -1
		theta = math.atan2(y, x)
		power = math.hypot(x, y)
		sin = math.sin(theta - math.pi/4)
		cos = math.cos(theta - math.pi/4)
		Max = max(abs(sin), abs(cos))
		leftFront = power * cos/Max + turn
		rightFront = power * sin/Max - turn
		leftBack = power * sin/Max + turn
		rightBack = power * cos/Max - turn

		if ((power + abs(turn)) > 1):
			leftFront /= (power + abs(turn))
			rightFront /= (power + abs(turn))
			leftBack /= (power + abs(turn))
			rightBack /= (power + abs(turn))		

		msg.linear.x = float(round(leftFront*255))
		msg.linear.y = float(round(rightFront*255))
		msg.angular.x = float(round(leftBack*255))
		msg.angular.y = float(round(rightBack*255))

		self.sent_drive.publish(msg)

		
		

	def gui(self):
		self.col = (0,255,0)
		detector = cv2.QRCodeDetector()
		img = self.img
		data, bbox, _ = detector.detectAndDecode(img)
		if bbox is not None and data:
			for i in range(len(bbox)):
				bbox_points = bbox[i].astype(int)
				if float(abs(bbox_points[0][0] - bbox_points[2][0]) * abs(bbox_points[0][1] - bbox_points[2][1])) >= 85000:
					self.status_walk = data
					self.col = (0,0,255)
				else:
					self.status_walk = "run"
				display = str(abs(bbox_points[0][0] - bbox_points[2][0]) * abs(bbox_points[0][1] - bbox_points[2][1]))
				cv2.rectangle(img, (bbox_points[0][0], bbox_points[0][1]), (bbox_points[2][0], bbox_points[2][1]), color=self.col, thickness=2)
				cv2.putText(img, data, (bbox_points[0][0], bbox_points[0][1] - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.5, self.col, 2)
				cv2.putText(img, display, (bbox_points[2][0] - 80 , bbox_points[2][1] + 20), cv2.FONT_HERSHEY_SIMPLEX, 0.5, self.col, 2)
		else:
			self.status_walk = "run"
		self.toggle_fullscreen()
		cv2.imshow("Webcam", self.img)
		if cv2.waitKey(1) & 0xFF == ord("q"):
			# closing all open windows
			cv2.destroyAllWindows()
			exit()

	def toggle_fullscreen(self):
		cv2.namedWindow("Webcam", cv2.WND_PROP_FULLSCREEN)
		if self.window_state == 'normal':
			cv2.setWindowProperty("Webcam", cv2.WND_PROP_FULLSCREEN, cv2.WINDOW_NORMAL)
		elif self.window_state == 'fullscreen':
			cv2.setWindowProperty("Webcam", cv2.WND_PROP_FULLSCREEN, cv2.WINDOW_FULLSCREEN)
		cv2.setMouseCallback("Webcam", self.mouse_callback)

	def mouse_callback(self, event, x, y, flags, param):
		if event == cv2.EVENT_LBUTTONUP:
			if(self.window_state) == 'normal':
				self.window_state = 'fullscreen'
			else:
				self.window_state = 'normal'

def main():
	rclpy.init()

	sub = Ps4()
	rclpy.spin(sub)

	rclpy.shutdown()

if __name__=="__main__":
	main()
