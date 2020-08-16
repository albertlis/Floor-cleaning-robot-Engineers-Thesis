//
// Created by Papa Smerf on 10.11.2019.
//

#include <wirish.h>
#include <Objects.h>
#include "functions.h"

void printInfoForPlot(double leftWheelVelovity, double rightWheelVelocity) {
    const constexpr u16 coordinatesPrescaler = 800;
    Serial << _FLOAT(targetCoordinates.getX(), 3) << ' '
            << _FLOAT(targetCoordinates.getY(), 3) << ' '
            << _FLOAT(robotCoordinates.getX(), 3) << ' '
           << _FLOAT(robotCoordinates.getY(), 3) << ' '
           << wheelSteringVelocities << ' '
           << _FLOAT(leftWheelVelovity, 3) << ' ' << _FLOAT(rightWheelVelocity, 3) << ' '
           << _FLOAT(targetCoordinates.getFi(), 3) << ' '
           << _FLOAT(robotCoordinates.getFi(), 3) << ' '
           << trajectoryGenerator.getVelocitiesVw() << ' '
           << robot.getVelocitiesVw() << ' '
           << millis() - startTime << endl;
    Serial.flush();
}

#ifdef DEBUG_KINEMATICS
void printDebugKinematicsInfo() {
   Serial << "Target coordinates: " << targetCoordinates << endl;
        Serial << "Reference velocities: " << referenceVelocities << endl;
        Serial << "Robot coordinates: " << robotKinematicsCoordinates << endl;
        Serial << "Errors: "<< errors << endl;
        Serial << "Reference errors: " << referenceErrors << endl;
        Serial << "Samson stering velocities: " << steringVelocities << endl;
}

#endif
