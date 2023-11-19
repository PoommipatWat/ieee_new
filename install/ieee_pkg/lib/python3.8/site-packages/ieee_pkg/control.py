import rclpy
from rclpy.node import Node
from rclpy.qos import qos_profile_sensor_data, qos_profile_system_default
from geometry_msgs.msg import Twist
from std_msgs.msg import Float32
from simple_pid import PID

class Control(Node):
    def __init__(self):
        super().__init__("control_node")

        # PID Left Wheel
        self.kp_l = self.declare_parameter('kp_l', 0.6).value
        self.ki_l = self.declare_parameter('ki_l', 0.8).value
        self.kd_l = self.declare_parameter('kd_l', 0.5).value
        
        self.kp_l = self.get_parameter('kp_l').get_parameter_value().double_value
        self.ki_l = self.get_parameter('ki_l').get_parameter_value().double_value
        self.kd_l = self.get_parameter('kd_l').get_parameter_value().double_value

        self.pid_l = PID(self.kp_l, self.ki_l, self.kd_l, setpoint=0)
        self.pid_l.output_limits = (-255, 255)
        
        # PID Right Wheel
        self.kp_r = self.declare_parameter('kp_r', 0.6).value
        self.ki_r = self.declare_parameter('ki_r', 0.8).value
        self.kd_r = self.declare_parameter('kd_r', 0.5).value
        
        self.kp_r = self.get_parameter('kp_r').get_parameter_value().double_value
        self.ki_r = self.get_parameter('ki_r').get_parameter_value().double_value
        self.kd_r = self.get_parameter('kd_r').get_parameter_value().double_value
        
        self.pid_r = PID(self.kp_r, self.ki_r, self.kd_r, setpoint=0)
        self.pid_r.output_limits = (-255, 255)
        
        self.subscription_encoder = self.create_subscription(
            Twist,
            "/encoder_topic",
            self.sub_callback_encoder,
            qos_profile_sensor_data
        )
        self.subscription_encoder
        self.rpm_l = 0
        self.rpm_r = 0
        self.ticks_l = 0
        self.ticks_r = 0
        
        self.publisher_pwm = self.create_publisher(
            Twist, "/control_drive_topic", qos_profile_system_default)
        
        self.subscription_leftwheel_pub = self.create_subscription(
            Float32,
            "/wheel_command_left",
            self.sub_callback_leftwheel_pub,
            10
        )
        self.subscription_leftwheel_pub
        
        self.subscription_rightwheel_pub = self.create_subscription(
            Float32,
            "/wheel_command_right",
            self.sub_callback_rightwheel_pub,
            10
        )
        self.subscription_rightwheel_pub

        self._logger.info("Control node has been started")

    def sub_callback_encoder(self, msg):
        # linear.x = left wheel ticks       # linear.y = left wheel rpm
        # angular.x = right wheel ticks     # angular.y = right wheel rpm
        self.ticks_l = msg.linear.x
        self.rpm_l = msg.linear.y
        self.ticks_r = msg.angular.x
        self.rpm_r = msg.angular.y

        self.kp_l = self.get_parameter('kp_l').get_parameter_value().double_value
        self.ki_l = self.get_parameter('ki_l').get_parameter_value().double_value
        self.kd_l = self.get_parameter('kd_l').get_parameter_value().double_value
        
        self.kp_r = self.get_parameter('kp_r').get_parameter_value().double_value
        self.ki_r = self.get_parameter('ki_r').get_parameter_value().double_value
        self.kd_r = self.get_parameter('kd_r').get_parameter_value().double_value
        
        self.pid_l.tunings = (self.kp_l, self.ki_l, self.kd_l)
        
        self.pid_r.tunings = (self.kp_r, self.ki_r, self.kd_r)
        
        output_l = self.pid_l(self.rpm_l)
        output_r = self.pid_r(self.rpm_r)
        self.publisher_drive_control(output_l, output_r)
    
    def publisher_drive_control(self, output_l, output_r):
        # linear.x = pwm_l      # linear.y = ina_l      # linear.z = inb_l
        # angular.x = pwm_r     # angular.y = ina_r     # angular.z = inb_r
        msg_publish = Twist()
        if output_l == 0 and output_r == 0:
            msg_publish.linear.x = 0.0
            msg_publish.linear.y = 1.0
            msg_publish.linear.z = 1.0
            msg_publish.angular.x = 0.0
            msg_publish.angular.y = 1.0
            msg_publish.angular.z = 1.0
        else:
            if output_l > 0:
                msg_publish.linear.x = float(abs(output_l))
                msg_publish.linear.y = 1.0
                msg_publish.linear.z = 0.0
            elif output_l < 0:
                msg_publish.linear.x = float(abs(output_l))
                msg_publish.linear.y = 0.0
                msg_publish.linear.z = 1.0
            if output_r > 0:
                msg_publish.angular.x = float(abs(output_r))
                msg_publish.angular.y = 1.0
                msg_publish.angular.z = 0.0
            elif output_r < 0:
                msg_publish.angular.x = float(abs(output_r))
                msg_publish.angular.y = 0.0
                msg_publish.angular.z = 1.0
        self.publisher_pwm.publish(msg_publish)
        
    def sub_callback_leftwheel_pub(self, msg):
        self.pid_l.setpoint = msg.data
        
    def sub_callback_rightwheel_pub(self, msg):
        self.pid_r.setpoint = msg.data

def main(args=None):
    rclpy.init(args=args)
    control_node = Control()

    try:
        rclpy.spin(control_node)
        control_node.get_logger().info("Shutting down control node by error")
    except KeyboardInterrupt:
        control_node.get_logger().info("Shutting down control node by keyboard interrupt")
    finally:
        # Log message before shutdown
        
        control_node.destroy_node()
        rclpy.shutdown()

if __name__ == "__main__":
    main()



if __name__ == "__main__":
    main()
