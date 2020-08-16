//
// Created by Papa Smerf on 05.10.2019.
//

#ifndef STMCOLLISIONDETECT_CLEANER_H
#define STMCOLLISIONDETECT_CLEANER_H

#include "Motor.h"
#include "Pins.h"
class Cleaner {
private:
    static constexpr u8 leftCleaner{cleanerLeftIn1PinPWM};
    static constexpr u8 rightCleaner{cleanerRightIn1PinPWM};
    u16 speed;
public:
    void start(u16 speed);
    void setSpeed(u16 speed);
    void stop();
};


#endif //STMCOLLISIONDETECT_CLEANER_H
