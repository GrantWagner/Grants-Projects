//file header

//header safeguards
#ifndef _BLOCK_DEVICE_HPP_
#define _BLOCK_DEVICE_HPP_

//needed includes
#include <cstdint>

using namespace std;

class BlockDevice {
public:
  void reset();

  uint8_t flags;
  uint8_t buffer[512];
  uint32_t writePtr;
  uint32_t readPtr;

  const uint8_t clear    = 0x00;
  const uint8_t busy     = 0x01;
  const uint8_t overflow = 0x02;
};

//more headersafeguards
#endif
