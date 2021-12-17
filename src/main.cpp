#include "Arduino.h"
#include "SerialStreamer.hpp"

void setup()
{
  Serial.begin(9600);
  pinMode(PC13, OUTPUT);
}

StreamParser Parser(Serial);

void loop()
{
  // delay(800);
  // Serial.println(0x1F);
  // delay(800);
  // Serial.println(0x1C);
  Parser.readHeader();
  digitalWrite(PC13, digitalRead(PC13) ^ 1);
  delay(200);
}