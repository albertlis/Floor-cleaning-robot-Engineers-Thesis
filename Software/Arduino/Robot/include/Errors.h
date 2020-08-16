//
// Created by Papa Smerf on 10.11.2019.
//

#ifndef ROBOT_ERRORS_H
#define ROBOT_ERRORS_H


#include <Coordinates.h>

class Errors {
private:
    double ex;
    double ey;
    double efi;
public:
    void calculate(const Coordinates &givenCoordinates, const Coordinates &robotCoordinates);
    double getEx() const;
    double getEy() const;
    double getEfi() const;

    friend Print &operator<<(Print &os, const Errors &errors);
};


#endif //ROBOT_ERRORS_H
