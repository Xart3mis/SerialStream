#include "Arduino.h"
#include "SerialStreamer.hpp"

void setup() { Serial.begin(9600); }

StreamParser Parser(Serial, 15);

void loop() {
  delay(800);
  Serial.println(0x1F);
  delay(800);
  Serial.println(0x1C);
}