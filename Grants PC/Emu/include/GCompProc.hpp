//file header

//header safeguards
#ifndef _G_COMP_PROC_HPP_
#define _G_COMP_PROC_HPP_

//needed includes
#include "BlockDevice.hpp"
#include <cstdint>

using namespace std;

const int max_operations = 68;

class GCompProc {
public:
  GCompProc( uint8_t *memory );
  bool ProcessInstruction();
  void Reset();

//private:
  uint8_t *memory;

  uint32_t registerA;
  uint32_t registerB;
  uint32_t registerJ;
  uint32_t registerProgramCounter;

  uint8_t flags;

  const uint8_t clear = 0;
  const uint8_t lessThan = 1;
  const uint8_t equalTo = 2;
  const uint8_t greaterThan = 3;

  const static uint8_t devicesCount = 2;
  BlockDevice devices[devicesCount];

  //array of function pointers, one for each
  void (*operations[max_operations])( GCompProc &proc, uint32_t P1, uint32_t P2 );
};

//more headersafeguards
#endif
