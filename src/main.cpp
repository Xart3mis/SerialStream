#include "Arduino.h"
#include "SerialStreamer.hpp"

void setup()
{
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
}

StreamParser Parser(Serial);
MessageHeader header;

void loop()
{
  Parser.readHeader();
  header = Parser.getHeader();

  if (header.start_marker == 0x1F && header.end_marker == 0x1E && header.timeout == 15)
  {
    for (byte i = 0; i < 20; i++)
    {
      digitalWrite(LED_BUILTIN, digitalRead(LED_BUILTIN) ^ 1);
      delay(50);
    }
  }
  digitalWrite(LED_BUILTIN, 0);
}