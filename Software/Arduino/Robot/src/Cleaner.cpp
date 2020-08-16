//
// Created by Papa Smerf on 05.10.2019.
//

#include <pwm.h>
#include <wirish.h>
#include <Streaming.h>
#include "Cleaner.h"
#include "debug.h"

void Cleaner::start(u16 speed) {
#ifdef DEBUG
    Serial << F("Starting Cleaner with speed: ") << speed << endl;
#endif
    this->speed = speed;
    pwmWrite(leftCleaner, speed);
    pwmWrite(rightCleaner, speed);
}

void Cleaner::setSpeed(u16 speed) {
#ifdef DEBUG
    Serial << F("Setting Cleaner speed: ") << speed << endl;
#endif
    start(speed);
}

void Cleaner::stop() {
#ifdef DEBUG
    Serial << F("Stopping Cleaner") << endl;
#endif
    pwmWrite(leftCleaner, 0);
    pwmWrite(rightCleaner, 0);
}
