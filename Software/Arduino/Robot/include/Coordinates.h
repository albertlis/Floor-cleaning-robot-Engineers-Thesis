//
// Created by Papa Smerf on 29.10.2019.
//

#ifndef ROBOT_COORDINATES_H
#define ROBOT_COORDINATES_H


#include <Streaming.h>
#include "Arduino.h"

class Coordinates {
private:
    double x;
    double y;
    double fi;
public:
    Coordinates();

    double getX() const;
    void setX(double x);
    double getY() const;
    void setY(double y);
    double getFi() const;
    void setFi(double fi);
    void setCoordinates(double x, double y, double fi);

    friend Print &operator<<(Print &os, const Coordinates &coordinates);
};


#endif //ROBOT_COORDINATES_H
