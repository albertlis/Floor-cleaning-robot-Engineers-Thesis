#include <Arduino.h>
#include <Servo.h>

constexpr uint8_t echoPin{PB12};
constexpr uint8_t trigPin{PB13};

uint16_t checkDistance()
{
    uint32_t time;
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    
    time = pulseIn(echoPin, HIGH, 1000000); //dla 350cm pomiar trwa 22ms
    return time / 58;
}

Servo ultrasonicSensor;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  ultrasonicSensor.attach(PA0);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}
int16_t pos{0};
void loop() {
    
for (pos = 0; pos < 180; ++pos) 
{ // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    // int startTime = millis();
    // checkDistance();
    // int stopTime = millis();
    // Serial.println(stopTime - startTime);
    String data = F("Angle ");
    data += String(pos, DEC);
    data += F(" Distance ");
    data += String(checkDistance(), DEC);
    Serial.println(data);
    delay(10);                       // waits 15ms for the servo to reach the position
}

for (pos = 180; pos > 0; --pos) 
{ // goes from 180 degrees to 0 degrees
    // int startTime = millis();
    // checkDistance();
    // int stopTime = millis();
    ultrasonicSensor.write(pos);              // tell servo to go to position in variable 'pos'
    String data = F("Angle ");
    data += String(pos, DEC);
    data += F(" Distance ");
    data += String(checkDistance(), DEC);
    Serial.println(data);
    delay(10);                       // waits 15ms for the servo to reach the position
  }
}