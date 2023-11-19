#ifndef IMU_H
#define IMU_H

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>

class Imu
{
public:
    void setup();
    void loop();
    float get_roll();
    float get_pitch();
    float get_yaw();
    float get_g_x();
    float get_g_y();
    float get_g_z();

private:
    Adafruit_BNO055 bno = Adafruit_BNO055(55, 0x29, &Wire);
    float roll = 0.0;
    float pitch = 0.0;
    float yaw = 0.0;
    float g_x = 0.0;
    float g_y = 0.0;
    float g_z = 0.0;
    void IMUEvent(sensors_event_t *event);
};

#endif
