//
// Created by Papa Smerf on 10.11.2019.
//

#include <RobotDimensions.h>
#include "WheelVelocities.h"

void WheelVelocities::calculateWheelSpeeds(const VelocitiesVW &velocitiesVw) {
    const double v = velocitiesVw.getV();
    const double w = velocitiesVw.getOmega();
    const double R = RobotDimensions::getWheelRadius();
    const double l = RobotDimensions::getRobotRadius();
    phi1RightWheel = ((v + (w * l)) / R) * radiansToRevolutionsPrescaler;
    phi2LeftWheel = ((v - (w * l)) / R) * radiansToRevolutionsPrescaler;
}

double WheelVelocities::getPhi1RightWheel() const {
    return phi1RightWheel;
}

double WheelVelocities::getPhi2LeftWheel() const {
    return phi2LeftWheel;
}

Print &operator<<(Print &os, const WheelVelocities &wheelSpeeds) {
//    os.print(F(" phi1RightWheel: "));
    os.print(wheelSpeeds.phi1RightWheel, 3);
//    os.print(F(" phi2LeftWheel: "));
    os.print(F(" "));
    os.print(wheelSpeeds.phi2LeftWheel, 3);
    return os;
}
