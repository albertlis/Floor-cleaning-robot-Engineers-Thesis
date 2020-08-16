//
// Created by Papa Smerf on 05.11.2019.
//

#include <math.h>
#include "ReferenceErrors.h"

ReferenceErrors::ReferenceErrors() : x(0.0), y(0.0), fi(0.0) {}

void ReferenceErrors::calculate(const Errors &errors, double fi) {
    const double ex = errors.getEx();
    const double ey = errors.getEy();

    x = (ex * cosf(fi)) + (ey * sinf(fi));
    y = (-sinf(fi) * ex) + (cosf(fi) * ey);
    ReferenceErrors::fi = errors.getEfi();
}

double ReferenceErrors::getX() const {
    return x;
}

double ReferenceErrors::getY() const {
    return y;
}

double ReferenceErrors::getFi() const {
    return fi;
}

Print &operator<<(Print &os, const ReferenceErrors &referenceErrors) {
    os.print(F("x: "));
    os.print(referenceErrors.getX());
    os.print(F(" y: "));
    os.print(referenceErrors.getY());
    os.print(F(" fi: "));
    os.print(referenceErrors.getFi());
    return os;
}
