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

void StreamParser::readshiz() {
  if (_Serialx.available()>=6)
  {
    for (byte i = 0; i < 6/2; i++)
    {
      for (byte i = 0; i < 2; i++)
      {

      }
      for (byte i = 0; i < 2; i++)
      {

      }
      for (byte i = 0; i < 2; i++)
      {
        /* code */
      }


    }
  }
}

StreamParser::StreamParser(Stream &Serialx, const uint16_t timeout): _Serialx(Serialx) {
    _Serialx.setTimeout(timeout);
};

StreamParser::~StreamParser(){};