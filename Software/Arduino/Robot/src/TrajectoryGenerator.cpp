//
// Created by Papa Smerf on 31.10.2019.
//

#include <Objects.h>
#include "TrajectoryGenerator.h"

TrajectoryGenerator::TrajectoryGenerator() : shouldTurnBackRight(false),
                                             shouldTurnBackLeft(false),
                                             shouldMoveStraightForward(true),
                                             shouldMoveStraightBackward(false) {
}

void TrajectoryGenerator::generateStraightForwardTrajectoryCoordinates() {
    const double actualX = coordinates.getX();
    if (actualX >= 1.0) {
        shouldMoveStraightForward = false;
        shouldTurnBackRight = true;
    }
    else {
        if (coordinates.getFi() != 0.0)
            coordinates.setFi(0.0);

        double nextX = actualX + xStep;
        const constexpr double vVelocity = xStep/timeIntevalSeconds;
        const constexpr double wVelocity{0.0};
        velocitiesVw.setVOmegaVelocities(vVelocity, wVelocity);
        coordinates.setX(nextX);
    }
}

void TrajectoryGenerator::generateStraightBackwardTrajectoryCoordinates() {
    double actualX = coordinates.getX();
    if (actualX <= 0.0) {
        shouldMoveStraightBackward = false;
        shouldTurnBackLeft = true;
    }
    else {
        if (coordinates.getFi() != PI)
            coordinates.setFi(PI);

        const double nextX = actualX - xStep;
        const constexpr double vVelocity = xStep/timeIntevalSeconds;
        const constexpr double wVelocity{0.0};

        velocitiesVw.setVOmegaVelocities(vVelocity, wVelocity);
        coordinates.setX(nextX);
    }
}

void TrajectoryGenerator::generateTurnBackRightCircularTrajectory() {
     const double actualFi = coordinates.getFi();
     static bool isCheckedStartXYPosition{false};

     if (actualFi >= PI) {
         shouldTurnBackRight = false;
         shouldMoveStraightBackward = true;
         isCheckedStartXYPosition = false;
     }
     else {
         static double startXPosition{0.0};
         static double startYPosition{0.0};

         if (!isCheckedStartXYPosition) {
             isCheckedStartXYPosition = true;
             startXPosition = coordinates.getX();
             startYPosition = coordinates.getY();
         }

         const constexpr double yPositionShift{0.1};
         const double tempFi = actualFi + fiStep - (PI / 2.0);
         const double nextX = 0.1 * cos(tempFi) + startXPosition;
         const double nextY = 0.1 * sin(tempFi) + startYPosition + yPositionShift;

         const double wVelocity = fiStep/timeIntevalSeconds;
         const double vVelocity = wVelocity * RobotDimensions::getRobotRadius();

         coordinates.setX(nextX);
         coordinates.setY(nextY);
         coordinates.setFi(tempFi + (PI / 2.0));
         velocitiesVw.setVOmegaVelocities(vVelocity, wVelocity);
     }
}

void TrajectoryGenerator::generateTurnBackLeftCircularTrajectory() {
    const double actualFi = coordinates.getFi();
    static bool isCheckedStartXYPosition{false};
    if (actualFi <= 0.0) {
        shouldTurnBackLeft = false;
        shouldMoveStraightForward = true;
        isCheckedStartXYPosition = false;
    }
    else {
        static double startXPosition{0.0};
        static double startYPosition{0.0};

        if (!isCheckedStartXYPosition) {
            isCheckedStartXYPosition = true;
            startXPosition = coordinates.getX();
            startYPosition = coordinates.getY();
        }

        const constexpr double yPositionShift{0.1};
        const double tempFi = actualFi - fiStep + PI / 2;
        const double nextX = 0.1 * cos(tempFi) + startXPosition;
        const double nextY = 0.1 * sin(tempFi) + startYPosition + yPositionShift;

        const double wVelocity = -fiStep/timeIntevalSeconds;
        const double vVelocity = -wVelocity * RobotDimensions::getRobotRadius();

        coordinates.setX(nextX);
        coordinates.setY(nextY);
        coordinates.setFi(tempFi - PI / 2.0);
        velocitiesVw.setVOmegaVelocities(vVelocity, wVelocity);
    }
}

void TrajectoryGenerator::generateTrajectory() {
    if (trajectoryGenerator.getCoordinates().getY() <= 1.205) {
        if (trajectoryGenerator.shouldMoveStraightForward)
            trajectoryGenerator.generateStraightForwardTrajectoryCoordinates();
        if (trajectoryGenerator.shouldTurnBackRight)
            trajectoryGenerator.generateTurnBackRightCircularTrajectory();
        if (trajectoryGenerator.shouldMoveStraightBackward)
            trajectoryGenerator.generateStraightBackwardTrajectoryCoordinates();
        if (trajectoryGenerator.shouldTurnBackLeft)
            trajectoryGenerator.generateTurnBackLeftCircularTrajectory();
    }
    else {
        velocitiesVw.setVOmegaVelocities(0.0, 0.0);
    }
}

u32 TrajectoryGenerator::getPreviousTime() const {
    return previousTime;
}

void TrajectoryGenerator::setPreviousTime(u32 previousTime) {
    TrajectoryGenerator::previousTime = previousTime;
}

const Coordinates &TrajectoryGenerator::getCoordinates() const {
    return coordinates;
}

const VelocitiesVW &TrajectoryGenerator::getVelocitiesVw() const {
    return velocitiesVw;
}



