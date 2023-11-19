import rclpy
from rclpy.node import Node
from rclpy.qos import qos_profile_sensor_data, qos_profile_system_default
from geometry_msgs.msg import Twist
from std_msgs.msg import String
from std_msgs.msg import Int32
import time


class IEEE(Node):
    def __init__(self):
        super().__init__("imu_control_node")

        self.subscription = self.create_subscription(
            Twist,
            "/imu_data",
            self.sub_callback,
            qos_profile_sensor_data
        )
        self.subscription

        self.subscription2 = self.create_subscription(
            String,
            "/command",
            self.sub_callback2,
            qos_profile_sensor_data
        )
        self.subscription2

        self.subscription3 = self.create_subscription(
            Int32,
            "/ultrasonic",
            self.sub_callback3,
            qos_profile_sensor_data
        )
        self.subscription3

        self.publisher = self.create_publisher(
            Twist, "/control_drive_topic", qos_profile_system_default)

        self.timer = self.create_timer(0.05, self.timer_callback)
        self.command = "Go straight"

        self.state = "wait"

        self.one_time = True

        self.roll = 0.0
        self.pitch = 0.0
        self.yaw = 0.0
        self.gx = 0.0
        self.gy = 0.0
        self.gz = 0.0

        self.target = 0.0

        self.keep_error = 0.01

        # Declare parameters with default values
        self.declare_parameter('pwm_max', 150.0)
        self.declare_parameter('pwm_min', 50.0)

        # Use the parameter values
        self.pwm_max = self.get_parameter(
            'pwm_max').get_parameter_value().double_value
        self.pwm_min = self.get_parameter(
            'pwm_min').get_parameter_value().double_value

        self.end_time = 0.0

        self.ultrasonic = 100
        self.distance = 50

    def printText(self, tex):
        self.get_logger().info(tex)

    def sub_callback(self, msg):
        self.roll = msg.linear.x
        self.pitch = msg.linear.y
        self.yaw = msg.linear.z
        self.gx = msg.angular.x
        self.gy = msg.angular.y
        self.gz = msg.angular.z

    def sub_callback2(self, msg):
        if self.ultrasonic < self.distance:
            self.command = msg.data

    def sub_callback3(self, msg):
        self.ultrasonic = msg.data

    def timer_callback(self):
        if self.state == "wait":
            self.control("Go straight")
            if self.command != "Go straight":
                self.state = self.command
        elif self.state == "Stop":
            self.control("Stop")
        elif self.state == "sleep":
            if time.time() > self.end_time:
                self.state = "wait"
            else:
                self.control("Stop")
        else:
            if self.control(self.state):
                self.control("Stop")
                self.state = "sleep"
                self.end_time = time.time() + 2.0

    def control(self, con):
        msg_pub = Twist()
        # linear.x = pwm_left       linear.y = ina_left       linear.z = inb_left
        # angular.x = pwm_right     angular.y = ina_right     angular.z = inb_right
        err, pwmm = self.find_error(self.roll, self.target)
        pwmm = float(round(pwmm))
        if con == "Turn Left":
            if self.one_time:
                self.target = self.minus_degree(self.roll, 90.0)
                self.one_time = False
            msg_pub.linear.x = pwmm
            msg_pub.angular.x = pwmm
            msg_pub.linear.y = 0.0
            msg_pub.angular.y = 1.0
            msg_pub.linear.z = 1.0
            msg_pub.angular.z = 0.0
            self.printText(f"{self. target} {self.roll} {err}")
            if err < self.keep_error:
                return True
        elif con == "Turn Right":
            if self.one_time:
                self.target = self.add_degrees(self.roll, 90.0)
                self.one_time = False
            msg_pub.linear.x = pwmm
            msg_pub.angular.x = pwmm
            msg_pub.linear.y = 1.0
            msg_pub.angular.y = 0.0
            msg_pub.linear.z = 0.0
            msg_pub.angular.z = 1.0
            self.printText(f"{self. target} {self.roll} {err}")
            if err < self.keep_error:
                return True
        elif con == "Turn Around":
            if self.one_time:
                self.target = self.minus_degree(self.roll, 180.0)
                self.one_time = False
            msg_pub.linear.x = pwmm
            msg_pub.angular.x = pwmm
            msg_pub.linear.y = 0.0
            msg_pub.angular.y = 1.0
            msg_pub.linear.z = 1.0
            msg_pub.angular.z = 0.0
            self.printText(f"{self. target} {self.roll} {err}")
            if err < self.keep_error:
                return True
        elif con == "Stop":
            msg_pub.linear.x = 0.0
            msg_pub.angular.x = 0.0
            msg_pub.linear.y = 1.0
            msg_pub.angular.y = 1.0
            msg_pub.linear.z = 1.0
            msg_pub.angular.z = 1.0
        elif con == "Go straight":
            self.one_time = True
            msg_pub.linear.x = self.pwm_max
            msg_pub.angular.x = self.pwm_max
            msg_pub.linear.y = 1.0
            msg_pub.angular.y = 1.0
            msg_pub.linear.z = 0.0
            msg_pub.angular.z = 0.0
        self.publisher.publish(msg_pub)
        return False

    def find_error(self, a, b):
        a = a % 360
        b = b % 360
        diff = abs(a - b)
        distance = min(diff, 360 - diff)
        pwmm = max(self.pwm_min, min(self.pwm_max, distance))
        return distance/180, max(50, min(150, distance))

    def add_degrees(self, a, b):
        result = a + b
        result %= 360
        return result

    def minus_degree(self, a, b):
        result = (a - b) % 360
        return result


def main(args=None):
    rclpy.init(args=args)
    ps4_controller_node = IEEE()

    try:
        rclpy.spin(ps4_controller_node)
    except KeyboardInterrupt:
        IEEE.printText("Keyboard Shutting Down")
    finally:
        ps4_controller_node.destroy_node()
        rclpy.shutdown()


if __name__ == "__main__":
    main()
