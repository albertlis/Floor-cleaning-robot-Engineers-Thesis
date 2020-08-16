//
// Created by Papa Smerf on 29.10.2019.
//

#ifndef ROBOT_SAMSONCONTROLLER_H
#define ROBOT_SAMSONCONTROLLER_H


#include <Print.h>
#include <VelocitiesVW.h>
#include "ReferenceErrors.h"

class SamsonController {
private:
    static const constexpr double k1{0.1};
    static const constexpr double k2{1.0};
    VelocitiesVW velocitiesVW;
public:
    void calculate(const ReferenceErrors &referenceErrors, const VelocitiesVW &referenceVelocities);

    double getK1() const;
    double getK2() const;
    const VelocitiesVW &getVelocitiesVw() const;

    friend Print &operator<<(Print &os, const SamsonController &samsonController);
};


#endif //ROBOT_SAMSONCONTROLLER_H
