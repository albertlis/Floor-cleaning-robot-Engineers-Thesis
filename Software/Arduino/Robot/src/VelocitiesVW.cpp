//
// Created by Papa Smerf on 05.11.2019.
//

#include "VelocitiesVW.h"

void VelocitiesVW::setVOmegaVelocities(double v, double omega) {
    VelocitiesVW::v = v;
    VelocitiesVW::omega = omega;
}

double VelocitiesVW::getV() const {
    return v;
}

void VelocitiesVW::setV(double v) {
    VelocitiesVW::v = v;
}

double VelocitiesVW::getOmega() const {
    return omega;
}

void VelocitiesVW::setOmega(double omega) {
    VelocitiesVW::omega = omega;
}

Print &operator<<(Print &os, const VelocitiesVW &velocities) {
//    os.print(F(" v: "));
    os.print(velocities.v);
    os.print(F(" "));
    os.print(velocities.omega);
    return os;
}
