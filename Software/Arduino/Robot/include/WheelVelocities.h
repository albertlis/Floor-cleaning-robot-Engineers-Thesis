//
// Created by Papa Smerf on 10.11.2019.
//

#ifndef ROBOT_WHEELVELOCITIES_H
#define ROBOT_WHEELVELOCITIES_H


#include <VelocitiesVW.h>

class WheelVelocities {
private:
    double phi1RightWheel;
    double phi2LeftWheel;
public:
    static const constexpr double radiansToRevolutionsPrescaler{0.1591549430919};

    void calculateWheelSpeeds(const VelocitiesVW &velocitiesVw);
    double getPhi1RightWheel() const;
    double getPhi2LeftWheel() const;

    friend Print &operator<<(Print &os, const WheelVelocities &wheelSpeeds);
};


#endif //ROBOT_WHEELVELOCITIES_H
