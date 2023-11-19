#include "encoder.h"
#include <Arduino.h>

void Encoder::setup()
{
    encoder1.attachHalfQuad(CLK1, DT1);
    encoder2.attachHalfQuad(CLK2, DT2);
    reset_count();
}

void Encoder::loop()
{
    find_count();
    find_RPM();
}

void Encoder::reset_count()
{
    encoder1.setCount(0);
    encoder2.setCount(0);
}

void Encoder::find_count()
{
    newPosition1 = encoder1.getCount();
    newPosition2 = encoder2.getCount();
}

long Encoder::get_encoder_left()
{
    return newPosition1;
}

long Encoder::get_encoder_right()
{
    return newPosition2;
}

void Encoder::find_RPM()
{
    int new_time = millis();
    int delta_time = new_time - old_time;
    if (delta_time == 0)
        return;
    old_time = new_time;
    float delta_position1 = newPosition1 - oldPosition1;
    float delta_position2 = newPosition2 - oldPosition2;
    oldPosition1 = newPosition1;
    oldPosition2 = newPosition2;

    float rpm1 = (delta_position1 / delta_time) * 60000 / PPR;
    float rpm2 = (delta_position2 / delta_time) * 60000 / PPR;
}

float Encoder::get_rpm_left()
{
    return rpm1;
}

float Encoder::get_rpm_right()
{
    return rpm2;
}
