//------------------------------------------------------------------------------------- import -----------------------------------------------------------------------//

//Xicro
  #include <Xicro_ieee_ID_1.h>
  Xicro xicro;


// Ultarsonic
  #define pingPin 17  //trig
  #define inPin 16    //echo
  uint32_t timestamp_ultrasonic = 0;

//Control
  String state_control = "waiting";
  String sub_command = "None";
  //(WHEEL 1)---------(WHEEL 2)
  //             |
  //             |
  //             |       
  //(WHEEL 3)---------(WHEEL 4)
    #define pin_w1_pwm -1
    #define pin_w2_pwm -1
    #define pin_w3_pwm -1
    #define pin_w4_pwm -1
    #define pin_w1_ina -1
    #define pin_w2_ina -1
    #define pin_w3_ina -1
    #define pin_w4_ina -1
    #define pin_w1_inb -1
    #define pin_w2_inb -1
    #define pin_w3_inb -1
    #define pin_w4_inb -1

//IMU
#include "GY521.h"
GY521 sensor(0x68);

//------------------------------------------------------------------------------------- main ------------------------------------------------------------------------//

void setup()
{
  Serial.begin(115200);
  xicro.begin(&Serial);

  Wire.begin();

  delay(100);
  while (sensor.wakeup() == false)
  {
    delay(1000);
  }
  sensor.setAccelSensitivity(2);  // 8g
  sensor.setGyroSensitivity(1);   // 500 degrees/s

  sensor.setThrottle();

  sensor.axe = -0.0520898;
  sensor.aye = -0.0011792;
  sensor.aze = -1.0190283;
  sensor.gxe = -0.0302290;
  sensor.gye = -0.0770229;
  sensor.gze = -1.5151145;

}

void loop()
{
  //publisher
  sensor.read();
  xicro.Spin_node(); // spin_node
  publisher();

  //subscriber
  int* val1 = subscriber(xicro.Subscription_control_msg.message.linear.x);
  int* val2 = subscriber(xicro.Subscription_control_msg.message.linear.y);
  int* val3 = subscriber(xicro.Subscription_control_msg.message.angular.x);
  int* val4 = subscriber(xicro.Subscription_control_msg.message.angular.y);
  drive(val1,val2,val3,val4);

}

//------------------------------------------------------------------------------------- method -----------------------------------------------------------------------//
void drive(int*val1, int*val2, int*val3, int*val4){
  digitalWrite(pin_w1_ina, val1[0]); digitalWrite(pin_w1_inb, val1[1]); analogWrite(pin_w1_pwm, val1[2]);
  digitalWrite(pin_w2_ina, val2[0]); digitalWrite(pin_w2_inb, val2[1]); analogWrite(pin_w2_pwm, val2[2]);
  digitalWrite(pin_w3_ina, val3[0]); digitalWrite(pin_w3_inb, val3[1]); analogWrite(pin_w3_pwm, val3[2]);
  digitalWrite(pin_w4_ina, val4[0]); digitalWrite(pin_w4_inb, val4[1]); analogWrite(pin_w4_pwm, val4[2]);
}

int* subscriber(int mg){
  int val[3];
  if(mg > 0){
    val[0] = 1;
    val[1] = 0;
    val[2] = mg;
  }
  else if(mg < 0){
    val[0] = 0;
    val[1] = 1;
    val[2] = -1*mg;
  }
  else{
    val[0] = 1;
    val[1] = 1;
    val[2] = mg;
  }
  return val;
}

void publisher()
{
  if (millis() - timestamp_ultrasonic >= 10)
  {
    timestamp_ultrasonic = millis();
    
    xicro.Publisher_yaw_msg.message.data = sensor.getYaw();
    xicro.publish_yaw_msg();
    xicro.Publisher_ultrasonic_msg.message.data = 1.00;
    xicro.publish_ultrasonic_msg();
  }
}

int read_ultra()
{
  unsigned long currentMillis = millis();
  long duration, cm;
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);
  pinMode(inPin, INPUT);
  duration = pulseIn(inPin, HIGH);
  cm = duration / 29 / 2;
  return cm;
}