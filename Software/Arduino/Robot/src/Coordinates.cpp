//
// Created by Papa Smerf on 29.10.2019.
//

#include "Coordinates.h"

Coordinates::Coordinates() : x(0), y(0), fi(0) {}

double Coordinates::getX() const {
    return x;
}

void Coordinates::setX(double x) {
    Coordinates::x = x;
}

double Coordinates::getY() const {
    return y;
}

void Coordinates::setY(double y) {
    Coordinates::y = y;
}

double Coordinates::getFi() const {
    return fi;
}

void Coordinates::setFi(double fi) {
    Coordinates::fi = fi;
}

void Coordinates::setCoordinates(double x, double y, double fi) {
    this->x = x;
    this->y = y;
    this->fi = fi;
}

Print &operator<<(Print &os, const Coordinates &coordinates) {
    os.print(F("x: "));
    os.print(coordinates.x);
    os.print(F(" y: ") );
    os.print(coordinates.y);
    os.print(F(" fi: "));
    os.print(coordinates.fi);
    return os;
}




