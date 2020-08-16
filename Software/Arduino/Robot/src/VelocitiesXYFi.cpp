//
// Created by Papa Smerf on 10.11.2019.
//

#include "VelocitiesXYFi.h"

VelocitiesXYFi::VelocitiesXYFi() : x(0.0), y(0.0), fi(0.0) {}

double VelocitiesXYFi::getX() const {
    return x;
}

void VelocitiesXYFi::setX(double x) {
    VelocitiesXYFi::x = x;
}

double VelocitiesXYFi::getY() const {
    return y;
}

void VelocitiesXYFi::setY(double y) {
    VelocitiesXYFi::y = y;
}

double VelocitiesXYFi::getFi() const {
    return fi;
}

void VelocitiesXYFi::setFi(double fi) {
    VelocitiesXYFi::fi = fi;
}


void VelocitiesXYFi::setXYFiVelocities(double x, double y, double fi) {
    VelocitiesXYFi::x = x;
    VelocitiesXYFi::y = y;
    VelocitiesXYFi::fi = fi;
}

Print &operator<<(Print &os, const VelocitiesXYFi &velocities) {
    os.print(F("x velocity: "));
    os.print(velocities.x);
    os.print(F(" y velocity: "));
    os.print(velocities.y);
    os.print(F(" fi velocity: "));
    os.print(velocities.fi);
    return os;
}