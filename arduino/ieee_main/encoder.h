#ifndef ENCODER_H
#define ENCODER_H

#include <ESP32Encoder.h>
#include "config.h"

class Encoder
{
public:
    void reset_count();
    void setup();
    void loop();
    long get_encoder_left();
    long get_encoder_right();
    float get_rpm_left();
    float get_rpm_right();

private:
    ESP32Encoder encoder1;
    ESP32Encoder encoder2;

    long newPosition1 = 0;
    long newPosition2 = 0;
    long oldPosition1 = 0;
    long oldPosition2 = 0;
    void find_count();

    int old_time = 0;
    float rpm1 = 0;
    float rpm2 = 0;
    void find_RPM();
};

#endif
