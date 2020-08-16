//
// Created by Papa Smerf on 05.10.2019.
//

#ifndef STMCOLLISIONDETECT_WATERPUMP_H
#define STMCOLLISIONDETECT_WATERPUMP_H


#include <usb_generic.h>

class WaterPump {
    u16 flow;
    const u8 waterPumpPin;
public:
    explicit WaterPump(u8 pin);

    void start(u16 flow);
    void setFlow(u16 flow);
    void stop();
};


#endif //STMCOLLISIONDETECT_WATERPUMP_H
