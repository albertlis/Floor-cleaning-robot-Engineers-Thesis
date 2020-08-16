//
// Created by Papa Smerf on 10.11.2019.
//

#ifndef ROBOT_ROBOTKINEMATICS_H
#define ROBOT_ROBOTKINEMATICS_H


#include "VelocitiesXYFi.h"
#include "Coordinates.h"
#include "TrajectoryGenerator.h"
#include "WheelVelocities.h"

class RobotKinematics {
private:
    VelocitiesXYFi velocitiesXYFi;
    Coordinates coordinates;
    VelocitiesVW velocitiesVw;
public:
    void calculate(const VelocitiesVW &givenVWVelocities, const WheelVelocities &wheelVelocities);

    const VelocitiesXYFi &getVelocitiesXYFi() const;
    const Coordinates &getCoordinates() const;
    const VelocitiesVW &getVelocitiesVw() const;
};


#endif //ROBOT_ROBOTKINEMATICS_H
