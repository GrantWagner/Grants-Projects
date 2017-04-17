
//file header

//header safeguards
#ifndef _INSTRUCTION_HPP_
#define _INSTRUCTION_HPP_

//needed includes
#include <cstdint>

using namespace std;

enum OperationSymbols {
  noOp = -1,
  Halt = 0,
  IOCpy = 65
};

class Instruction {
public:
  OperationSymbols opCode = noOp;
  bool endOfFile = false;

};

//more headersafeguards
#endif
