#include "drive.h"

void Drive::set_drive_left(float pwm, float ina, float inb)
{
    digitalWrite(INAL, ina);
    digitalWrite(INBL, inb);
    analogWrite(PWML, pwm);
}

void Drive::set_drive_right(float pwm, float ina, float inb)
{
    digitalWrite(INAR, ina);
    digitalWrite(INBR, inb);
    analogWrite(PWMR, pwm);
}
