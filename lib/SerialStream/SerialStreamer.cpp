#include "SerialStreamer.hpp"

void StreamParser::clearInputBuffer() {
  while (_Serialx.available())
  {
    _Serialx.read();
  }
}

void StreamParser::test(uint16_t waittime) {
  auto star = [&] { _Serialx.print("* "); };

  for(int i = 8; i >= 1; --i)
  {
    for(int space = 0; space < 8-i; ++space)
        _Serialx.print("  ");

    for (int j = i; j <= 2 * i - 1; ++j) star();
    for (int j = 0; j < i - 1; ++j) star();

    _Serialx.println();
  }

  delay(waittime);
}

void StreamParser::readHeader() {
  char temp[2] = {0};

  /*312815*/

  if (_Serialx.available()>=6)
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

StreamParser::StreamParser(Stream &Serialx): _Serialx(Serialx), header(){};

StreamParser::~StreamParser(){};