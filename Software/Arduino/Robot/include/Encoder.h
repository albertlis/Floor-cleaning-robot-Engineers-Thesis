//
// Created by Papa Smerf on 30.10.2019.
//

#ifndef ROBOT_ENCODER_H
#define ROBOT_ENCODER_H

#include <usb/usb_lib/usb_lib.h>

class Encoder {
    constexpr static double impulsesPerRevolution{40.0};
    constexpr static double gear{48.0};
    double wheelSpeedRevolutions;
    double wheelSpeedRadians;
public:
    u32 impulsesCounter;
    void resetCounter();
    void calculateWheelVelocities();

    double getWheelSpeedRevolutions() const;
    double getWheelSpeedRadians() const;
};


#endif //ROBOT_ENCODER_H
