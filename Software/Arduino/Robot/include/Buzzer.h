//
// Created by Papa Smerf on 20.10.2019.
//

#ifndef ROBOT_BUZZER_H
#define ROBOT_BUZZER_H


#include <usb/usb_lib/usb_lib.h>
#include "debug.h"

class Buzzer {
public:
#ifdef DEBUG
    static const constexpr u32 DEBUG_FREQUENCY{500};
    static const constexpr u32 DEBUG_PERIOD{1000};
#endif
    void start(u32 frequency);
    void stop();
    void beep(u32 frequency, u32 period);
};


#endif //ROBOT_BUZZER_H
