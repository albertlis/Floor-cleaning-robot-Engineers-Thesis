//
// Created by Papa Smerf on 05.10.2019.
//

#ifndef STMCOLLISIONDETECT_ROBOT_H
#define STMCOLLISIONDETECT_ROBOT_H

#include <Coordinates.h>
#include <Encoder.h>
#include "Motor.h"
#include "Pins.h"
#include "WaterPump.h"
#include "VelocitiesXYFi.h"
#include "Cleaner.h"
#include "WheelVelocities.h"

class Robot {
public:
    Coordinates coordinates;
    VelocitiesVW velocitiesVw;
    Encoder encoderLeft;
    Encoder encoderRight;
    Motor motorLeft;
    Motor motorRight;
    WaterPump waterPump;
    Cleaner cleaner;
    bool obstacleDetected;
    Robot();
    void stop();
    void brake();
    void calculateWheelVelocities();
    void calculateCoordinates();
    const Coordinates &getCoordinates() const;
    const VelocitiesVW &getVelocitiesVw() const;
};


#endif //STMCOLLISIONDETECT_ROBOT_H
