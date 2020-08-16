//
// Created by Papa Smerf on 05.11.2019.
//

#ifndef ROBOT_REFERENCEERRORS_H
#define ROBOT_REFERENCEERRORS_H


#include "Errors.h"

class ReferenceErrors {
private:
    double x;
    double y;
    double fi;
public:
    ReferenceErrors();

    double getX() const;
    double getY() const;
    double getFi() const;

    void calculate(const Errors &errors, double fi);
    friend Print &operator<<(Print &os, const ReferenceErrors &referenceErrors);
};


#endif //ROBOT_REFERENCEERRORS_H
