import rclpy
from rclpy.node import Node
from std_msgs.msg import Int16
from std_msgs.msg import Float32
from geometry_msgs.msg import Twist
from std_msgs.msg import String
import math
import time

class control(Node):

    def __init__(self):  
        super().__init__("control_ieee_node")
        self.sub_webcam =  self.create_subscription(
            String,
            "/command",
            self.callback_webcam,
            10
        )
        self.sub_webcam
        self.command_webcam = "No QR code detected"
        
        self.sub_ultrasonic =  self.create_subscription(
            Int16,
            "/ultrasonic_msg",
            self.callback_ultrasonic,
            10
        )
        self.sub_ultrasonic
        self.ultrasonic = 999
        
        self.sub_webcam
        self.command_webcam = "No QR code detected"
        
        self.sub_yaw =  self.create_subscription(
            Float32,
            "/yaw_msg",
            self.callback_yaw,
            10
        )
        self.sub_yaw
        self.yaw = 0.0
        
        self.timer_ = self.create_timer(0.005,self.timer_call)
        
        self.pub = self.create_publisher(
            Twist,
            "/control_msg",
            10
        )
        
        self.state = 0
        self.com = None
        
        self.target = None
        self.keep_data = None
        self.comfirm = None
        
        self.t0 = None
        self.t0_once = True
        
        self.t0_command = 0
        
        self.com_once = True
        
        self.init_pwm = 0
    
    def callback_webcam(self, msg):
        self.command_webcam = msg.data
        
        
    def callback_ultrasonic(self, msg):
        self.ultrasonic = msg.data
    
    def callback_yaw(self, msg):
        self.yaw = int(msg.data)
  
    def timer_call(self):
        msg = self.mechanum(0,0,0)
        if (self.state == 0 and self.command_webcam != "No QR code detected" and self.ultrasonic <= 30) or self.com_once == False:
            self._logger.info("reading QR Code")
            msg = self.mechanum(0,0,0)
            if self.t0_once:
                self.t0 = time.time()
                self.t0_once = False  
            if self.com_once:
                self.com = self.command_webcam
                self.com_once = False
            if self.com == "Turn Left":
                self.target = self.yaw + 90
            elif self.com == "Turn Right":
                self.target = self.yaw - 90
            elif self.com == "Turn Around":
                if self.yaw >= 180:
                    self.target = self.yaw - 180
                else:
                    self.target = self.yaw + 180
            self.keep_data = []
            if (time.time() - self.t0) >= 3:
                self.state = 1
                self.t0_once = True
                self.com_once = True
        elif self.state == 1:
            self.keep_data.append(self.yaw)
            
            if len(self.keep_data) < 20:
                lenn = len(self.keep_data)*-1
            else:
                lenn = -20
            
            s = 0
            if self.comfirm != "Turn Left":
                if ((self.keep_data[lenn] <= 100 and self.keep_data[lenn] >= 0) or self.comfirm == "Turn Right") and self.keep_data[-1] >= 240 and self.keep_data[-1] <= 360:
                    self.comfirm = "Turn Right"
                    self.yaw = self.yaw-360
                    s = 1
            if self.comfirm != "Turn Right":
                if ((self.keep_data[lenn] >= 260 and self.keep_data[lenn] <= 360) or self.comfirm == "Turn Left") and self.keep_data[-1] >= 0 and self.keep_data[-1] <= 100:
                    self.comfirm = "Turn Left"
                    self.yaw += 360
                    s = 2
            
            error = (abs(self.yaw - self.target))/90/1.5
            
            if self.com == "Turn Left":
                msg = self.mechanum(0,0,((-1*error)-self.init_pwm))
            elif self.com == "Turn Right":
                msg = self.mechanum(0,0,(1*error))
            elif self.com == "Turn Around":
                if self.target >= 180:
                    msg = self.mechanum(0,0,(-1*error)-self.init_pwm)
                else:
                    msg = self.mechanum(0,0,(1*error)+self.init_pwm)
                    
            self._logger.info(f"yaw: {self.yaw}, target: {self.target}, state: {self.state}, com: {s}")
            
            if (self.yaw == self.target):
                self.state = 2
                self._logger.info("go to state 2")
                self.keep_data = []
                self.comfirm = ""
                
        elif self.state == 2:
            msg = self.mechanum(0,0,0)
            if self.t0_once:
                self.t0 = time.time()
                self.t0_once = False
            if time.time() - self.t0 >= 3:
                self.state = 0
                self.t0_once = True
                self._logger.info("go to state 0")
            self._logger.info("i am in state 2")
            
        # elif self.state == 0 and self.command_webcam == "No QR code detected" and self.ultrasonic <= 30:
        #     msg = self.mechanum(0,0,0)
        #     if self.t0_once:
        #         self.t0 = time.time()
        #         self.t0_once = False
        #         self._logger.info("Found an obstacle")
        #     if time.time() - self.t0 >= 2:
        #         self.state = 11
        #         self.t0_once = True
                
        # elif self.state == 11:
        #     msg = self.mechanum(0.6,0,0)
        #     if self.ultrasonic >= 1:
        #         self.state = 12
                
        # elif self.state == 12:
        #     msg = self.mechanum(0.6,0,0)
        #     if self.t0_once:
        #         self.t0 = time.time()
        #         self.t0_once = False
        #         self._logger.info("Avoided an obstacle")
        #     if time.time() - self.t0 >= 2:
        #         self.state = 0
        #         self.t0_once = True
                
        elif self.state == 0:
            msg = self.mechanum(0.6,0,0)
            self._logger.info("i am in state 0")
            self.t0_once = True
        
        self.pub.publish(msg)
            
    def mechanum(self, y,x,turn):
        max_power = 255
        msg = Twist()
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

        msg.linear.x = float(round(leftFront*max_power))
        msg.linear.y = float(round(rightFront*max_power))
        msg.angular.x = float(round(leftBack*max_power))
        msg.angular.y = float(round(rightBack*max_power))
        return msg
            
  
def main(args=None):
    rclpy.init(args=args)
    node = control()
    rclpy.spin(node)
    rclpy.shutdown()
  
if __name__ == "__main__":
    main() 