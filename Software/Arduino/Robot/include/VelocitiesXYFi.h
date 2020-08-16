//
// Created by Papa Smerf on 10.11.2019.
//

#ifndef ROBOT_VELOCITIESXYFI_H
#define ROBOT_VELOCITIESXYFI_H

#include <Print.h>
#include <RobotDimensions.h>

class VelocitiesXYFi {
private:
    double x;
    double y;
    double fi;
public:
    VelocitiesXYFi();

    friend Print &operator<<(Print &os, const VelocitiesXYFi &velocities);

    double getX() const;
    void setX(double x);
    double getY() const;
    void setY(double y);
    double getFi() const;
    void setFi(double fi);
    void setXYFiVelocities(double x, double y, double fi);
};

#endif //ROBOT_VELOCITIESXYFI_H
