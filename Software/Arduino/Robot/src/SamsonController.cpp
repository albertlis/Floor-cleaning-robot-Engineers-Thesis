//
// Created by Papa Smerf on 29.10.2019.
//

#include <math.h>
#include "SamsonController.h"

void SamsonController::calculate(const ReferenceErrors &referenceErrors, const VelocitiesVW &referenceVelocities) {
    const double v = (k1 * referenceErrors.getX()) + (referenceVelocities.getV() * cosf(referenceErrors.getFi()));
    const double w = referenceVelocities.getOmega() + (k2 * referenceErrors.getFi()) + (referenceVelocities.getV() * referenceErrors.getY());

    velocitiesVW.setVOmegaVelocities(v, w);
}

const VelocitiesVW &SamsonController::getVelocitiesVw() const {
    return velocitiesVW;
}

double SamsonController::getK1() const {
    return k1;
}

double SamsonController::getK2() const {
    return k2;
}

Print &operator<<(Print &os, const SamsonController &samsonController) {
    os.print(F(" k1: "));
    os.print(samsonController.k1);
    os.print(F(" k2: "));
    os.print(samsonController.k2);
    return os;
}