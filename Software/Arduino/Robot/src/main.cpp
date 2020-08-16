//
// Created by Papa Smerf on 05.10.2019.
//
#include "Objects.h"
#include "setupFunctions.h"
#include <Streaming.h>
#include <TrajectoryGenerator.h>
#include "functions.h"
#include "ISRfunctions.h"

void setup() {
    Serial.begin(7200000);
//    Serial.begin(115200);
    setupInputPins();
    setupOutputPins();
    setupInterrupts();
    buzzer.stop();
//    robot.cleaner.stop();
    digitalWrite(waterMotorsLowPin, LOW);
    analogWrite(waterPumpPinPWM, 60);
    analogWrite(waterSuckerPinPWM, 255);
    robot.cleaner.start(UINT16_MAX/2);
    delay(1000);
    startTime = millis();
    robot.obstacleDetected = false;
}

u8 counter{0};
//u16 printTime{0};
bool state;
bool previous;
void loop() {
//    bool reading = digitalRead(buttonPin);
//    if(reading == LOW  && previous == HIGH)
//        state = !state;
//    previous = reading;
//    Serial << state << endl;
//    if(state == LOW)
//        robot.stop();

    if(((!digitalRead(rightBumperPinEXTI)) || (!digitalRead(leftBumperPinEXTI))) || digitalRead(frontRightFloorSensorPinEXTI) || digitalRead(frontLeftFloorSensorPinEXTI))
        robot.obstacleDetected = true;
    else
        robot.obstacleDetected = false;

    u32 actualTime = millis();
    if((actualTime - trajectoryGenerator.getPreviousTime() > TrajectoryGenerator::timeIntervalMs)  && !robot.obstacleDetected ) { //&& state == HIGH)
        trajectoryGenerator.setPreviousTime(actualTime);
//        Serial << "KUERWWWWWWWWWWWWAAAAAAAAAAAA" << endl;

//        u32 startTime = micros();
        ++counter;
        trajectoryGenerator.generateTrajectory();

        targetCoordinates = trajectoryGenerator.getCoordinates();
        referenceVelocities = trajectoryGenerator.getVelocitiesVw();
//        robotKinematicsCoordinates = robotKinematics.getCoordinates();
        robot.calculateWheelVelocities();
        robot.calculateCoordinates();
        robotCoordinates = robot.getCoordinates();

//        errors.calculate(targetCoordinates, robotKinematicsCoordinates);
//        referenceErrors.calculate(errors, robotKinematicsCoordinates.getFi());
        errors.calculate(targetCoordinates, robotCoordinates);
        referenceErrors.calculate(errors, robotCoordinates.getFi());

        samsonController.calculate(referenceErrors, referenceVelocities);
        steringVelocities = samsonController.getVelocitiesVw();
        wheelSteringVelocities.calculateWheelSpeeds(steringVelocities);
        
//        robotKinematics.calculate(steringVelocities, wheelSteringVelocities);
//        robotVWVelocities = robotKinematics.getVelocitiesVw();

//        u32 endTime = micros();


        double leftWheelTargetVelocityRevolutions = wheelSteringVelocities.getPhi2LeftWheel();
        double rightWheelTargetVelocityRevolutions = wheelSteringVelocities.getPhi1RightWheel();

        robot.motorLeft.setTargetRevolutionsVelocity(leftWheelTargetVelocityRevolutions);
        robot.motorRight.setTargetRevolutionsVelocity(rightWheelTargetVelocityRevolutions);

        double leftWheelRevolutionsVelocity = robot.encoderLeft.getWheelSpeedRevolutions();
        double rightWheelRevolutionsVelocity = robot.encoderRight.getWheelSpeedRevolutions();
        u16 dutyLeft = robot.motorLeft.calculateDuty(leftWheelRevolutionsVelocity);
        u16 dutyRight = robot.motorRight.calculateDuty(rightWheelRevolutionsVelocity);

        robot.motorLeft.moveForward(dutyLeft);
        robot.motorRight.moveForward(dutyRight);

//        printInfoForPlot(leftWheelRevolutionsVelocity, rightWheelRevolutionsVelocity);

/*
        if( counter == 100) {
            Serial  << "Left: " << robot.encoderLeft.getWheelSpeedRevolutions()
                    << "\tRight: " << robot.encoderRight.getWheelSpeedRevolutions() << endl;
            counter = 0;
        }
        */
//        Serial << wheelSteringVelocities << endl;
//        Serial << endTime - startTime << endl;


#ifdef DEBUG_KINEMATICS
        printDebugKinematicsInfo();
#endif
    }
//    if(actualTime - printTime > 100)
//        printInfoForPlot();
}
