#ifndef StreamParser_H
#define StreamParser_H

#include "Arduino.h"

#ifndef PAYLOAD_SIZE
#define PAYLOAD_SIZE 1000
#endif // !PAYLOAD_SIZE

struct MessageHeader
{
  uint16_t timeout;

  char start_marker;
  char end_marker;
};

enum RXStatus
{
  RX_COMPLETE,    // message complete
  RX_INCOMPLETE,  // message not complete yet
  RX_ERR_START,   // startbytes mismatch
  RX_ERR_TIMEOUT, // timeout error
  RX_ERR_SIZE,    // payload bytes will not fit
  RX_ERR_CS       // checksum error
};

struct MessagePayload
{
  static uint32_t payload[PAYLOAD_SIZE];

  static uint16_t header_size;
  static uint16_t length;

  static RXStatus status;
};

class StreamParser
{
private:
  Stream &_Serialx;
  MessageHeader header;

  void clearInputBuffer();
  void readMessageHeader();

public:
  void readHeader();
  void test(uint16_t waittime);

  MessagePayload getPayload();
  MessageHeader getHeader();

  StreamParser(Stream &Serialx);
  ~StreamParser();
};
#endif // !StreamParser_H

//https://forum.arduino.cc/t/arduino-mega-receive-big-amount-of-data-by-serial-port/544764/4