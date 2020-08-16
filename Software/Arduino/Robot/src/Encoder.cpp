//
// Created by Papa Smerf on 30.10.2019.
//

#include <Objects.h>
#include "Encoder.h"

void Encoder::resetCounter() {
    impulsesCounter = 0;
}

void Encoder::calculateWheelVelocities() {
    wheelSpeedRevolutions = impulsesCounter / (impulsesPerRevolution * gear) * (1000.0 / TrajectoryGenerator::timeIntervalMs);
    wheelSpeedRadians = wheelSpeedRevolutions * 2 * PI;;
}

double Encoder::getWheelSpeedRevolutions() const {
    return wheelSpeedRevolutions;
}

double Encoder::getWheelSpeedRadians() const {
    return wheelSpeedRadians;
}
