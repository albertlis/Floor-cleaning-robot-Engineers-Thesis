//
// Created by Papa Smerf on 07.10.2019.
//

#include "setupFunctions.h"
#include "Pins.h"
#include "ISRfunctions.h"
#include <Arduino.h>

void setupInputPins() {
    pinMode(leftBumperPinEXTI, INPUT_PULLUP);
    pinMode(rightBumperPinEXTI, INPUT_PULLUP);
    pinMode(frontLeftFloorSensorPinEXTI, INPUT);
    pinMode(frontRightFloorSensorPinEXTI, INPUT);

    pinMode(encoderLeftPinEXTI, INPUT);
    pinMode(encoderRightPinEXTI, INPUT);
}

void setupOutputPins() {
    pinMode(motorLeftIn1PinPWM, PWM);
    pinMode(motorLeftIn2PinPWM, PWM);
    pinMode(motorRightIn1PinPWM, PWM);
    pinMode(motorRightIn2PinPWM, PWM);
    pinMode(waterPumpPinPWM, OUTPUT);
    pinMode(cleanerLeftIn1PinPWM, PWM);
    pinMode(cleanerRightIn1PinPWM, PWM);
    pinMode(buzzerPinPWM, PWM);
    pinMode(waterSuckerPinPWM, OUTPUT);

    pinMode(waterMotorsLowPin, OUTPUT);
    pinMode(buttonPin, INPUT);
    pinMode(waterLevelPin, INPUT_PULLUP);
}

void setupInterrupts() {
//    attachInterrupt(digitalPinToInterrupt(leftBumperPinEXTI), leftBumperISR, FALLING);
//    attachInterrupt(digitalPinToInterrupt(rightBumperPinEXTI), rightBumperISR, FALLING);
//    attachInterrupt(digitalPinToInterrupt(frontLeftFloorSensorPinEXTI), frontLeftFloorSensorISR, FALLING);
//    attachInterrupt(digitalPinToInterrupt(frontRightFloorSensorPinEXTI), frontRightFloorSensorISR, FALLING);
//    attachInterrupt(digitalPinToInterrupt(bottomLeftFloorSensorPinEXTI), bottomLeftFloorSensorISR, FALLING);
//    attachInterrupt(digitalPinToInterrupt(bottomRightFloorSensorPinEXTI), bottomRightFloorSensorISR, FALLING);
    attachInterrupt(digitalPinToInterrupt(encoderLeftPinEXTI), encoderLeftISR, CHANGE);
    attachInterrupt(digitalPinToInterrupt(encoderRightPinEXTI), encoderRightISR, CHANGE);
}
