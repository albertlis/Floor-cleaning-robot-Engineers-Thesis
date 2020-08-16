//
// Created by Papa Smerf on 31.10.2019.
//

#ifndef ROBOT_TRAJECTORYGENERATOR_H
#define ROBOT_TRAJECTORYGENERATOR_H


#include <usb/usb_lib/usb_lib.h>
#include "Coordinates.h"
#include "VelocitiesVW.h"

class TrajectoryGenerator {
public:
    static const constexpr u16 timeIntervalMs{10};
    static const constexpr double timeIntevalSeconds{timeIntervalMs/1000.0};
private:
    static const constexpr double xStep{0.001};
    static const constexpr double fiStep{(PI/4) * timeIntevalSeconds};
    Coordinates coordinates;
    VelocitiesVW velocitiesVw;
    u32 previousTime{0};
    bool shouldTurnBackRight;
    bool shouldTurnBackLeft;
    bool shouldMoveStraightForward;
    bool shouldMoveStraightBackward;

    void generateStraightForwardTrajectoryCoordinates();
    void generateStraightBackwardTrajectoryCoordinates();
    void generateTurnBackRightCircularTrajectory();
    void generateTurnBackLeftCircularTrajectory();
public:
    TrajectoryGenerator();

    void generateTrajectory();

    u32 getPreviousTime() const;
    void setPreviousTime(u32 previousTime);
    const Coordinates &getCoordinates() const;
    const VelocitiesVW &getVelocitiesVw() const;
};


#endif //ROBOT_TRAJECTORYGENERATOR_H
