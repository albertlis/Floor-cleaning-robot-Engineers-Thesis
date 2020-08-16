//
// Created by Papa Smerf on 10.11.2019.
//

#include "RobotKinematics.h"

void RobotKinematics::calculate(const VelocitiesVW &givenVWVelocities, const WheelVelocities &wheelVelocities) {
    const double v = givenVWVelocities.getV();
    const double w = givenVWVelocities.getOmega();
    const double phi1RightWheel = wheelVelocities.getPhi1RightWheel();
    const double phi2LeftWheel = wheelVelocities.getPhi2LeftWheel();
    const double wheelRadius = RobotDimensions::getWheelRadius();
    const double robotRadius = RobotDimensions::getRobotRadius();

    velocitiesXYFi.setFi(w);
    const double fi = coordinates.getFi() + (w * TrajectoryGenerator::timeIntevalSeconds);

    const double xVelocity = v * cos(fi);
    const double yVelocity = v * sin(fi);

    const double xPosition = coordinates.getX() + (xVelocity * TrajectoryGenerator::timeIntevalSeconds);
    const double yPosition = coordinates.getY() + (yVelocity * TrajectoryGenerator::timeIntevalSeconds);

    const double robotVVelocity = (wheelRadius/2.0) * (phi1RightWheel + phi2LeftWheel) / WheelVelocities::radiansToRevolutionsPrescaler;
    const double robotWVelocity = (wheelRadius/(2.0 * robotRadius)) * (phi1RightWheel - phi2LeftWheel) / WheelVelocities::radiansToRevolutionsPrescaler;

    coordinates.setX(xPosition);
    coordinates.setY(yPosition);
    coordinates.setFi(fi);
    velocitiesVw.setVOmegaVelocities(robotVVelocity, robotWVelocity);
}

const VelocitiesXYFi &RobotKinematics::getVelocitiesXYFi() const {
    return velocitiesXYFi;
}

const Coordinates &RobotKinematics::getCoordinates() const {
    return coordinates;
}

const VelocitiesVW &RobotKinematics::getVelocitiesVw() const {
    return velocitiesVw;
}

