//
// Created by Papa Smerf on 05.10.2019.
//

#include "ISRfunctions.h"
#include "Objects.h"
#include "debug.h"
#include "Streaming.h"

void bumperISR() {
#ifdef DEBUG
    Serial << F("leftBumperISR") << endl;
#endif
    robot.stop();
    robot.obstacleDetected = true;
}
/*
void rightBumperISR() {
#ifdef DEBUG
    Serial << F("RightBumperISR") << endl;
#endif
    robot.stop();
    robot.obstacleDetected = true;
}*/
void frontFloorSensorISR() {
#ifdef DEBUG
    Serial << F("frontLeftFloorSensorISR") << endl;
#endif
//    Serial << "Sensor"<< endl;
    robot.obstacleDetected = true;
    robot.stop();
}
/*
void frontRightFloorSensorISR() {
#ifdef DEBUG
    Serial << F("frontRightFloorSensorISR") << endl;
#endif
//    Serial << "Sensor "<< endl;
    robot.obstacleDetected = true;
    robot.stop();
}
/*
void bottomLeftFloorSensorISR() {
#ifdef DEBUG
    Serial << F("bottomLeftFloorSensorISR") << endl;
#endif
    robot.brake();
}
void bottomRightFloorSensorISR() {
#ifdef DEBUG
    Serial << F("bottomRightFloorSensorISR") << endl;
#endif
    robot.brake();
}
*/
void encoderLeftISR() {
    ++robot.encoderLeft.impulsesCounter;
}

void encoderRightISR() {
    ++robot.encoderRight.impulsesCounter;
}
