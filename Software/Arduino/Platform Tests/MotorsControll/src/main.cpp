#include <Arduino.h>

/**
 * Motor controler
 *  IN1 IN2 
 *  H   L   - forward
 *  L   H   - backward
 *  L   L   - off
 *  H   H   - braking
 */

/** !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 * 
 *      Do enkodera trzeba kondensatory bo czyta wiele pików
 * 
 *  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 */

const constexpr uint8_t IN1{7};
const constexpr uint8_t IN2{6};
const constexpr uint8_t IN3{5};
const constexpr uint8_t IN4{4};
const constexpr uint8_t leftWheelEncoder{3};
const constexpr uint8_t rightWheelEncoder{2};

uint32_t counter{0};

void rightWheelEncoderISR()
{
    ++counter;
    //delayMicroseconds(1000);
}

void setup() {
  // put your setup code here, to run once:
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);

  pinMode(rightWheelEncoder,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(rightWheelEncoder), rightWheelEncoderISR, CHANGE);

  Serial.begin(9600);
}
bool state = LOW;
void loop() {
  digitalWrite(IN1,HIGH);
  //digitalWrite(IN3,HIGH);
  //analogWrite(IN1, 100);
  //analogWrite(IN3, 100);
  delay(1000);
  digitalWrite(IN1,LOW);
  digitalWrite(IN3,LOW);
  delay(1000);
  Serial.println(counter);
  counter = 0;
}