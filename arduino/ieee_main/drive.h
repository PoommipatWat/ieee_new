#ifndef DRIVE_H
#define DRIVE_H

#include <Arduino.h>
#include "config.h"

class Drive
{
public:
    void set_drive_left(float pwm, float ina, float inb);
    void set_drive_right(float pwm, float ina, float inb);
};

#endif
