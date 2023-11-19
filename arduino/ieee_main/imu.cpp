#include "imu.h"

void Imu::setup()
{
    if (!bno.begin())
    {
        while (0)
            ;
    }
}

void Imu::loop()
{
    sensors_event_t orientationData, gravityData;
    bno.getEvent(&orientationData, Adafruit_BNO055::VECTOR_EULER);
    bno.getEvent(&gravityData, Adafruit_BNO055::VECTOR_GRAVITY);
    IMUEvent(&orientationData);
    IMUEvent(&gravityData);
}

void Imu::IMUEvent(sensors_event_t *event)
{
    if (event->type == SENSOR_TYPE_ORIENTATION)
    {
        roll = event->orientation.x;
        pitch = event->orientation.y;
        yaw = event->orientation.z;
    }
    else if (event->type == SENSOR_TYPE_GRAVITY)
    {
        g_x = event->acceleration.x;
        g_y = event->acceleration.y;
        g_z = event->acceleration.z;
    }
}

float Imu::get_roll()
{
    return roll;
}

float Imu::get_pitch()
{
    return pitch;
}

float Imu::get_yaw()
{
    return yaw;
}

float Imu::get_g_x()
{
    return g_x;
}

float Imu::get_g_y()
{
    return g_y;
}

float Imu::get_g_z()
{
    return g_z;
}
