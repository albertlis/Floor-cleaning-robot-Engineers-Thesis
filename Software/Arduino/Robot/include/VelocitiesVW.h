//
// Created by Papa Smerf on 05.11.2019.
//

#ifndef ROBOT_VELOCITIESVW_H
#define ROBOT_VELOCITIESVW_H


#include <Print.h>

class VelocitiesVW {
private:
    double v;
    double omega;

public:
    void setVOmegaVelocities(double v, double omega);
    friend Print &operator<<(Print &os, const VelocitiesVW &velocities);

    double getV() const;
    void setV(double v);
    double getOmega() const;
    void setOmega(double omega);
};


#endif //ROBOT_VELOCITIESVW_H
