//
// Created by Papa Smerf on 20.10.2019.
//

#include <tone.h>
#include <Pins.h>
#include "Buzzer.h"

void Buzzer::start(u32 frequency) {
    tone(buzzerPinPWM, frequency);
}

void Buzzer::stop() {
    tone(buzzerPinPWM, 0);
}

void Buzzer::beep(u32 frequency, u32 period) {
    u32 actualTime = millis();
    static u32 previousTime;
    static bool isRunning = false;
    if ((actualTime - previousTime) > period) {
        previousTime = actualTime;
        if (!isRunning) {
            tone(buzzerPinPWM, frequency);
            isRunning = true;
        }
        else {
            tone(buzzerPinPWM, 0);
            isRunning = false;
        }
    }
}
