//
// Created by Papa Smerf on 10.11.2019.
//

#include "Errors.h"

void Errors::calculate(const Coordinates &givenCoordinates, const Coordinates &robotCoordinates) {
    const double xd = givenCoordinates.getX();
    const double yd = givenCoordinates.getY();
    const double fid = givenCoordinates.getFi();

    const double x = robotCoordinates.getX();
    const double y = robotCoordinates.getY();
    const double fi = robotCoordinates.getFi();

    ex = xd - x;
    ey = yd - y;
    efi = fid - fi;
}

double Errors::getEx() const {
    return ex;
}

double Errors::getEy() const {
    return ey;
}

double Errors::getEfi() const {
    return efi;
}

Print &operator<<(Print &os, const Errors &errors) {
    os.print("ex: ");
    os.print(errors.getEx());
    os.print(" ey: ");
    os.print(" efi: ");
    os.print(errors.getEfi());
    return os;
}

