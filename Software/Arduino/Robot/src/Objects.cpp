//
// Created by Papa Smerf on 05.10.2019.
//
#include "Objects.h"
#include "Pins.h"

Robot robot;
//RobotKinematics robotKinematics;
Buzzer buzzer;
SamsonController samsonController;
TrajectoryGenerator trajectoryGenerator;

Coordinates targetCoordinates;
Coordinates robotKinematicsCoordinates;
Coordinates robotCoordinates;
VelocitiesVW referenceVelocities;
VelocitiesVW steringVelocities;
//VelocitiesVW robotVWVelocities;
Errors errors;
ReferenceErrors referenceErrors;
WheelVelocities wheelSteringVelocities;

u32 startTime;

