//
// Created by Papa Smerf on 05.10.2019.
//
#include <Arduino.h>
#include "Motor.h"
#include "debug.h"
#include <Streaming.h>

void Motor::moveForward(u16 speed) {
#ifdef DEBUG
    Serial << F("Motor moving forward with speed") <<  speed << endl;
#endif
    pwmWrite(IN1, speed);
    pwmWrite(IN2, 0);
}

void Motor::moveBackward(u16 speed) {
#ifdef DEBUG
    Serial << F("Motor moving backward with speed") <<  speed << endl;
#endif
    pwmWrite(IN2, speed);
    pwmWrite(IN1, 0);
}

void Motor::stop() {
#ifdef DEBUG
    Serial << F("Motor stopping") <<  endl;
#endif
    pwmWrite(IN2, 0);
    pwmWrite(IN1, 0);
}

void Motor::brake() {
#ifdef DEBUG
    Serial << F("Motor breaking") <<  endl;
#endif
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, HIGH);
}

Motor::Motor(const u8 in1, const u8 in2) :  IN1(in1), IN2(in2), targetRevolutionsVelocity(0.0),
                                            duty(20000) {}

void Motor::setTargetRevolutionsVelocity(double targetRevolutionsVelocity) {
    Motor::targetRevolutionsVelocity = targetRevolutionsVelocity;
}

u16 Motor::calculateDuty(const double actualRevolutionsVelocity) {
    if (fabs(targetRevolutionsVelocity - actualRevolutionsVelocity) > 0.2)
        regulationStep = 1000;
    else
        regulationStep = 100;
    if(actualRevolutionsVelocity < targetRevolutionsVelocity)
        duty = (duty >= (UINT16_MAX - 1001)) ? UINT16_MAX : duty + regulationStep;
    else
        duty = (duty <= 1001) ? 0 : duty - regulationStep;
    return duty;
}
