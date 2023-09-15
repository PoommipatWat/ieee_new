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
  sensor.read();
  xicro.Spin_node(); // spin_node
  publisher();

}

//------------------------------------------------------------------------------------- method -----------------------------------------------------------------------//

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