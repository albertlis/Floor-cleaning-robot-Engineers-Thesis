//
// Created by Papa Smerf on 05.10.2019.
//

#include <pwm.h>
#include "WaterPump.h"
#include "debug.h"
#include "Streaming.h"

WaterPump::WaterPump(u8 pin) : flow(0), waterPumpPin(pin) {}

void WaterPump::start(u16 flow) {
#ifdef DEBUG
    Serial << F("Starting water pump") << endl;
#endif
    this->flow = flow;
    pwmWrite(waterPumpPin, flow);
}

void WaterPump::setFlow(u16 flow) {
#ifdef DEBUG
    Serial << F("Setting water pump flow") << endl;
#endif
    start(flow);
}

void WaterPump::stop() {
#ifdef DEBUG
    Serial << F("Stoping water pump") << endl;
#endif
    pwmWrite(waterPumpPin, 0);
}
