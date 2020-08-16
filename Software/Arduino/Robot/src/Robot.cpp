//
// Created by Papa Smerf on 05.10.2019.
//

#include <TrajectoryGenerator.h>
#include "Robot.h"
#include "Streaming.h"
#include "debug.h"
#include "Pins.h"

Robot::Robot() :    motorLeft(Motor(motorLeftIn1PinPWM, motorLeftIn2PinPWM)),
                    motorRight(Motor(motorRightIn1PinPWM, motorRightIn2PinPWM)),
                    waterPump(WaterPump(waterPumpPinPWM)) {}

void Robot::stop() {
#ifdef DEBUG
    Serial << F("Stoping robot") << endl;
#endif
    motorLeft.stop();
    motorRight.stop();
}

void Robot::brake() {
#ifdef DEBUG
    Serial << F("Breaking robot") << endl;
#endif
    motorLeft.brake();
    motorRight.brake();
}

void Robot::calculateWheelVelocities() {
    encoderLeft.calculateWheelVelocities();
    encoderLeft.resetCounter();
    encoderRight.calculateWheelVelocities();
    encoderRight.resetCounter();
}

void Robot::calculateCoordinates() {
    const double phi1RightWheelRadians = encoderRight.getWheelSpeedRadians();
    const double phi2LeftWheelRadians = encoderLeft.getWheelSpeedRadians();

    const double wheelRadius = RobotDimensions::getWheelRadius();
    const double robotRadius = RobotDimensions::getRobotRadius();

    const double v = (wheelRadius/2) * (phi1RightWheelRadians + phi2LeftWheelRadians);
    const double w = (wheelRadius/(2 * robotRadius)) * (phi1RightWheelRadians - phi2LeftWheelRadians);

    const double fi = coordinates.getFi() + (w * TrajectoryGenerator::timeIntevalSeconds);

    const double xVelocity = v * cos(fi);
    const double yVelocity = v * sin(fi);

    const double xPosition = coordinates.getX() + (xVelocity * TrajectoryGenerator::timeIntevalSeconds);
    const double yPosition = coordinates.getY() + (yVelocity * TrajectoryGenerator::timeIntevalSeconds);

    coordinates.setX(xPosition);
    coordinates.setY(yPosition);
    coordinates.setFi(fi);

    velocitiesVw.setVOmegaVelocities(v , w);
}

const Coordinates &Robot::getCoordinates() const {
    return coordinates;
}

const VelocitiesVW &Robot::getVelocitiesVw() const {
    return velocitiesVw;
}

