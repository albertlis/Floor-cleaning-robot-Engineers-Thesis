//
// Created by Papa Smerf on 05.10.2019.
//

#ifndef STMCOLLISIONDETECT_OBJECTS_H
#define STMCOLLISIONDETECT_OBJECTS_H

#include <SamsonController.h>
#include "Robot.h"
#include "Buzzer.h"
#include "TrajectoryGenerator.h"
#include "RobotKinematics.h"
#include "WheelVelocities.h"

extern Robot robot;
//extern RobotKinematics robotKinematics;
extern Buzzer buzzer;
extern SamsonController samsonController;
extern TrajectoryGenerator trajectoryGenerator;

extern Coordinates targetCoordinates;
extern Coordinates robotKinematicsCoordinates;
extern Coordinates robotCoordinates;
extern VelocitiesVW referenceVelocities;
extern VelocitiesVW steringVelocities;
//extern VelocitiesVW robotVWVelocities;
extern Errors errors;
extern ReferenceErrors referenceErrors;
extern WheelVelocities wheelSteringVelocities;

extern u32 startTime;

#endif //STMCOLLISIONDETECT_OBJECTS_H
