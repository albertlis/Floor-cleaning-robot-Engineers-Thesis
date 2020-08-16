//
// Created by Papa Smerf on 05.10.2019.
//

#ifndef STMCOLLISIONDETECT_MOTOR_H
#define STMCOLLISIONDETECT_MOTOR_H


#include <usb_generic.h>

class Motor {
private:
    const u8 IN1;
    const u8 IN2;
    double targetRevolutionsVelocity;
    u16 duty;
    u16 regulationStep;
public:
    void moveForward(u16 speed);
    void moveBackward(u16 speed);
    void stop();
    void brake();
    u16 calculateDuty(double actualRevolutionsVelocity);
    Motor(u8 in1, u8 in2);

    void setTargetRevolutionsVelocity(double targetRevolutionsVelocity);
};


#endif //STMCOLLISIONDETECT_MOTOR_H
