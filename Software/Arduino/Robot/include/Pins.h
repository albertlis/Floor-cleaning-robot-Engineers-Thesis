//
// Created by Papa Smerf on 05.10.2019.
//

#ifndef STMCOLLISIONDETECT_PINS_H
#define STMCOLLISIONDETECT_PINS_H

#include <usb_generic.h>
#include <Arduino.h>

const constexpr u8 leftBumperPinEXTI{PB1}, rightBumperPinEXTI{PB13};
const constexpr u8 frontLeftFloorSensorPinEXTI{PB3}, frontRightFloorSensorPinEXTI{PB4}; // cacy
//const constexpr u8 bottomLeftFloorSensorPinEXTI{PB5}, bottomRightFloorSensorPinEXTI{PB8};
const constexpr u8 encoderLeftPinEXTI{PB10}, encoderRightPinEXTI{PB11};

//silniki zaczynają kręcić od wypełnienia 25k Piny są ok
const constexpr u8 motorLeftIn1PinPWM{PA0}, motorLeftIn2PinPWM{PA1};
const constexpr u8 motorRightIn1PinPWM{PA2}, motorRightIn2PinPWM(PA3);
const constexpr u8 waterSuckerPinPWM{PA8};
const constexpr u8 waterPumpPinPWM{PB8};
const constexpr u8 cleanerLeftIn1PinPWM{PB6}; //w razie W zamienić Pin PWM
const constexpr u8 cleanerRightIn1PinPWM{PB7}; //w razie W zamienić Pin PWM
const constexpr u8 buzzerPinPWM{PA6};

const constexpr u8 waterMotorsLowPin{PB5};//pa9
const constexpr u8 waterLevelPin{PB15};
constexpr u8 buttonPin{PA9};

#endif //STMCOLLISIONDETECT_PINS_H
