#include "SerialStreamer.hpp"

void StreamParser::clearInputBuffer()
{
  while (_Serialx.available())
  {
    _Serialx.read();
  }
}

void StreamParser::test(uint16_t waittime)
{
  auto star = [&]
  { _Serialx.print("* "); };

  for (int i = 8; i >= 1; --i)
  {
    for (byte space = 0; space < 8 - i; ++space)
      _Serialx.print("  ");

    for (byte j = i; j <= 2 * i - 1; ++j)
      star();
    for (byte j = 0; j < i - 1; ++j)
      star();

    _Serialx.println();
  }

  delay(waittime);
}

void StreamParser::readHeader()
{
  char temp[2] = {0};

  /*312815*/

  if (_Serialx.available() >= 6)
  {
    temp[0] = Serial.read();
    temp[1] = Serial.read();
    header.start_marker = atoi(temp);

    temp[0] = 0;
    temp[1] = 0;
    temp[0] = Serial.read();
    temp[1] = Serial.read();
    header.end_marker = atoi(temp);

    temp[0] = 0;
    temp[1] = 0;
    temp[0] = Serial.read();
    temp[1] = Serial.read();
    header.timeout = atoi(temp);
  }
}

MessageHeader StreamParser::getHeader()
{
  MessageHeader temphead;
  temphead = header;
  memset(&header, 0, sizeof(MessageHeader));
  return temphead;
}

StreamParser::StreamParser(Stream &Serialx) : _Serialx(Serialx), header(), payload(){};
StreamParser::~StreamParser(){};