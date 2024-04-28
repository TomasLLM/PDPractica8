#include <Arduino.h>

#define RXD0 34
#define TXD0 35
#define TXD2 28

void setup() {
  Serial.begin(4000);
  Serial1.begin(4000, SERIAL_8N1, RXD0, TXD2);
  Serial2.begin(4000, SERIAL_8N1, TXD2, TXD0);
}

void loop() {
  // Serial.printf("A");
  if(Serial.available())
  {
    Serial1.write(Serial.read());  
  }
  if(Serial1.available())
  {
    Serial2.write(Serial1.read());
    Serial.printf("Test");
  }
  delay(10);
}