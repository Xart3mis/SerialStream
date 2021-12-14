#include "Arduino.h"
#include "SerialStreamer.hpp"

void setup() { Serial.begin(9600); }

StreamParser Parser(Serial, 15);

void loop() {
  Parser.test(500);
}