//------------------------------------------------------------------------------------- import -----------------------------------------------------------------------//

//Xicro
  #include <Xicro_ieee_ID_1.h>
  Xicro xicro;
  uint32_t timestamp = 0;

// Ultarsonic
  #define pingPin 17
  #define inPin 16

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

    #define speed_wheel 150


//------------------------------------------------------------------------------------- main ------------------------------------------------------------------------//

void setup()
{
  Serial.begin(115200);
  xicro.begin(&Serial);
}

void loop()
{
  xicro.Spin_node(); // spin_node
  publisher_ultrasonic();

  if((xicro.Subscription_control_msg.message.data != "None") && (state_control == "waiting")){
    state_control = "running";
    sub_command = xicro.Subscription_control_msg.message.data;
  }
  if(state_control == "running"){
    control(sub_command);
    state_control = "clear";
  }
  if(state_control == "clear"){
    sub_command = "None";
    state_control = "waiting";
  }
}

//------------------------------------------------------------------------------------- method -----------------------------------------------------------------------//



void control(String com){
  if(com == "Turn Right") mechanum(1,-1,1,-1);
  else if(com == "Turn Left") mechanum(-1,1,-1,1);
  else if(com == "Stop") mechanum(0,0,0,0);
  else if(com == "Turn Around") mechanum(1,-1,1,-1);
  else if(com == "Go straight") mechanum(1,1,1,1);
  else if(com == " Backwards") mechanum(-1,-1,-1,-1);
  else if(com == "Right") mechanum(1,-1,-1,1);
  else if(com == "Left") mechanum(-1,1,1,-1);
}

void mechanum(int dir1, int dir2, int dir3, int dir4){
    if (dir1 == 1){
      analogWrite(pin_w1_pwm, speed_wheel);
      digitalWrite(pin_w1_ina, HIGH);
      digitalWrite(pin_w1_inb, LOW);
    }
    else if (dir1 == -1){
      analogWrite(pin_w1_pwm, speed_wheel);
      digitalWrite(pin_w1_ina, LOW);
      digitalWrite(pin_w1_inb, HIGH);
    }
    else{
      digitalWrite(pin_w1_pwm, LOW);
      digitalWrite(pin_w1_ina, HIGH);
      digitalWrite(pin_w1_inb, HIGH);      
    }
    if (dir2 == 1){
      analogWrite(pin_w2_pwm, speed_wheel);
      digitalWrite(pin_w2_ina, HIGH);
      digitalWrite(pin_w2_inb, LOW);
    }
    else if (dir2 == -1){
      analogWrite(pin_w2_pwm, speed_wheel);
      digitalWrite(pin_w2_ina, LOW);
      digitalWrite(pin_w2_inb, HIGH);
    }
    else{
      digitalWrite(pin_w2_pwm, LOW);
      digitalWrite(pin_w2_ina, HIGH);
      digitalWrite(pin_w2_inb, HIGH);      
    }
    if (dir3 == 1){
      analogWrite(pin_w3_pwm, speed_wheel);
      digitalWrite(pin_w3_ina, HIGH);
      digitalWrite(pin_w3_inb, LOW);
    }
    else if (dir3 == -1){
      analogWrite(pin_w3_pwm, speed_wheel);
      digitalWrite(pin_w3_ina, LOW);
      digitalWrite(pin_w3_inb, HIGH);
    }
    else{
      digitalWrite(pin_w3_pwm, LOW);
      digitalWrite(pin_w3_ina, HIGH);
      digitalWrite(pin_w3_inb, HIGH);      
    }
    if (dir4 == 1){
      analogWrite(pin_w4_pwm, speed_wheel);
      digitalWrite(pin_w4_ina, HIGH);
      digitalWrite(pin_w4_inb, LOW);
    }
    else if (dir4 == -1){
      analogWrite(pin_w4_pwm, speed_wheel);
      digitalWrite(pin_w4_ina, LOW);
      digitalWrite(pin_w4_inb, HIGH);
    }
    else{
      digitalWrite(pin_w4_pwm, LOW);
      digitalWrite(pin_w4_ina, HIGH);
      digitalWrite(pin_w4_inb, HIGH);      
    }
}

void publisher_ultrasonic()
{
  if (millis() - timestamp >= 50)
  {
    timestamp = millis();
    xicro.Publisher_ultrasonic_msg.message.data = read_ultra();
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