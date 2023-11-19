import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist, Pose2D, TransformStamped
from std_msgs.msg import Float32
from nav_msgs.msg import Odometry
from rclpy.qos import qos_profile_sensor_data, qos_profile_system_default
import math
import tf2_ros

class Robot(Node):
    def __init__(self):
        super().__init__('robot_core_node')
        #------------------------------------------config------------------------------------------
        self.wheel_radius = 7.5/100 #m
        self.wheelbase = 35/100 #m
        self.max_rpm = 60 #rpm
        self.tick_per_rev = 2500
        #------------------------------------------------------------------------------------------

        self.vel_sub = self.create_subscription(Twist, 'cmd_vel', self.vel_callback,10)

        self.leftwheel_pub = self.create_publisher(Float32, 'wheel_command_left', 10)
        self.rightwheel_pub = self.create_publisher(Float32, 'wheel_command_right', 10)

        self.v = 0.0
        self.w = 0.0

        self.timer = self.create_timer(0.04,self.timer_callback)

        self.cmd_l = Float32()
        self.cmd_r = Float32()
        
        self.subscription_encoder = self.create_subscription(
            Twist,
            "/encoder_topic",
            self.tick_callback,
            qos_profile_sensor_data
        )        
        self.left_tick = {"bf":None, "now":None}
        self.right_tick = {"bf":None, "now":None}
        self.left_tick_ts = None
        self.right_tick_ts = None
        
        self.last_time = self.get_clock().now()

        self.robot_pose = Pose2D()
        self.dx = 0.0
        self.dy = 0.0
        self.dtheta = 0.0
        
        self.odom_pub = self.create_publisher(Odometry, 'odom', 10)
        
        #TF
        self.tf_broadcaster = tf2_ros.TransformBroadcaster(self)
        
        self.get_logger().info("robot core has been started")
        
    def tick_callback(self, tick_in):
        ts = self.get_clock().now()
        self.left_tick["now"] = tick_in.linear.x
        self.left_tick_ts = ts
        self.right_tick["now"] = tick_in.angular.x
        self.right_tick_ts = ts
        
    def get_tick(self):
        tick = {}
        tick['l'] = self.left_tick["now"]
        tick['r'] = self.right_tick["now"]
        tick['lts'] = self.left_tick_ts
        tick['rts'] = self.right_tick_ts
        return tick

    def vel_callback(self, vel):
        print("callback function")
        self.v = vel.linear.x
        self.w = vel.angular.z

        L = self.wheelbase
        R = self.wheel_radius

        v_r = ((2.0*self.v)+(self.w*L))/(2.0*R)
        v_l = ((2.0*self.v)-(self.w*L))/(2.0*R)
        print("v_r: ",v_r)
        print("v_l: ",v_l)
        self.wheel_speed_setpoint(v_r,v_l)
        
    def timer_callback(self):
        self.leftwheel_pub.publish(self.cmd_l)
        self.rightwheel_pub.publish(self.cmd_r)
        self.odometry()

    def wheel_speed_setpoint(self,vr,vl):
        rpm_r = vr*9.549297
        rpm_l = vl*9.549297  #1 rad/s = 9.549297 rpm

        rpm_r = max(min(rpm_r,self.max_rpm), -self.max_rpm)
        rpm_l = max(min(rpm_l,self.max_rpm), -self.max_rpm)

        if rpm_r == 0.0:
            self.cmd_r.data = 0.0
        if rpm_l == 0.0:
            self.cmd_l.data = 0.0
        self.cmd_l.data = float(rpm_l)
        self.cmd_r.data = float(rpm_r)

        self.get_logger().info('out left rpm: %s' %rpm_l)
        self.get_logger().info('out right rpm: %s' %rpm_r)
        
    def quaternion_to_euler(self, roll, pitch, yaw):
        cy = math.cos(yaw*0.5)
        sy = math.sin(yaw*0.5)
        cp = math.cos(pitch*0.5)
        sp = math.sin(pitch*0.5)
        cr = math.cos(roll*0.5)
        sr = math.sin(roll*0.5)
        q = [0]*4
        q[0] = cy * cp * cr + sy * sp * sr
        q[1] = cy * cp * sr - sy * sp * cr
        q[2] = sy * cp * sr + cy * sp * cr
        q[3] = sy * cp * cr - cy * sp * sr
        return q
                
        
    def odometry(self):
        ts = self.get_clock().now()
        tick = self.get_tick()
        dt = ts - self.last_time #nanosecond
        dt = dt.nanoseconds*1e-9 #second
        
        if tick['l'] is None or tick['r'] is None:
            return
        
        if self.right_tick["bf"] is None or self.left_tick["bf"] is None:
            self.right_tick["bf"] = tick['r']
            self.left_tick["bf"] = tick['l']

        prev_robot_pose = self.robot_pose
        R = self.wheel_radius
        L = self.wheelbase
        TPR = self.tick_per_rev
        
        DPT = (2*math.pi*R)/TPR
        
        DL = DPT*(tick['l'] - self.left_tick["bf"])
        DR = DPT*(tick['r'] - self.right_tick["bf"])
        
        DC = (DL+DR)/2.0
        
        self.dx = DC*math.cos(self.robot_pose.theta)
        self.dy = DC*math.sin(self.robot_pose.theta)
        self.dtheta = (DR-DL)/L
        
        new_robot_pose = Pose2D()  
        new_robot_pose.x = prev_robot_pose.x + self.dx
        new_robot_pose.y = prev_robot_pose.y + self.dy
        new_robot_pose.theta = prev_robot_pose.theta + self.dtheta
        
        self.robot_pose.x = new_robot_pose.x
        self.robot_pose.y = new_robot_pose.y
        self.robot_pose.theta = new_robot_pose.theta
        
        self.left_tick["bf"] = tick['l']
        self.right_tick["bf"] = tick['r']
        
        odom = Odometry()
        odom.header.stamp = self.get_clock().now().to_msg()
        odom.header.frame_id = "odom"
        odom.child_frame_id = "base_link"
        odom.pose.pose.position.x = self.robot_pose.x
        odom.pose.pose.position.y = self.robot_pose.y
        odom.pose.pose.position.z = 0.0
        odom.pose.pose.orientation.x = 0.0
        quat = self.quaternion_to_euler(0.0, 0.0, self.robot_pose.theta)
        odom.pose.pose.orientation.w = quat[0]
        odom.pose.pose.orientation.x = quat[1]
        odom.pose.pose.orientation.y = quat[2]
        odom.pose.pose.orientation.z = quat[3]
        
        self.odom_pub.publish(odom)
        
        t = TransformStamped()
        t.header.stamp = self.get_clock().now().to_msg()
        t.header.frame_id = "odom"
        t.child_frame_id = "base_link"
        t.transform.translation.x = self.robot_pose.x
        t.transform.translation.y = self.robot_pose.y
        t.transform.translation.z = 0.0
        t.transform.rotation.w = quat[0]
        t.transform.rotation.x = quat[1]
        t.transform.rotation.y = quat[2]
        t.transform.rotation.z = quat[3]
        
        self.tf_broadcaster.sendTransform(t)
        
        self.last_time = ts

def main(args=None):
    rclpy.init(args=args)
    robot_core_node = Robot()

    try:
        rclpy.spin(robot_core_node)
        robot_core_node.get_logger().info("Shutting down robot core node by error")
    except KeyboardInterrupt:
        robot_core_node.get_logger().info("Shutting down robot core node by keyboard interrupt")
    finally:
        # Log message before shutdown
        robot_core_node.destroy_node()
        rclpy.shutdown()

if __name__ == "__main__":
    main()