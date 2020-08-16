//
// Created by Papa Smerf on 10.11.2019.
//

#ifndef ROBOT_FUNCTIONS_H
#define ROBOT_FUNCTIONS_H

#include "debug.h"

void printInfoForPlot(double leftWheelVelovity, double rightWheelVelocity);
#ifdef DEBUG_KINEMATICS
void printDebugKinematicsInfo();
#endif

#endif //ROBOT_FUNCTIONS_H
