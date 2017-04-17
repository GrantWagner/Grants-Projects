//file header

//required includes
#include "GCompProc.hpp"
#include <stdio.h>

//operation definition functions
void LoadA( GCompProc &proc, uint32_t P1, uint32_t P2 ) {
  int index = P1 + P2;
  uint32_t operand1 = proc.memory[index];

  proc.registerA = operand1;
} // LoadA

void LoadB( GCompProc &proc, uint32_t P1, uint32_t P2 ) {
  int index = P1 + P2;
  uint32_t operand1 = proc.memory[index];

  proc.registerB = operand1;
} // LoadB

void LoadJ( GCompProc &proc, uint32_t P1, uint32_t P2 ) {
  int index = P1 + P2;
  uint32_t operand1 = proc.memory[index];

  proc.registerJ = operand1;
} // LoadJ

void StoreA( GCompProc &proc, uint32_t P1, uint32_t P2 ) {
  int index = P1 + P2;
  uint32_t operand1 = proc.registerA;

  proc.memory[index] = operand1;
} // StoreA

void StoreB( GCompProc &proc, uint32_t P1, uint32_t P2 ) {
  int index = P1 + P2;
  uint32_t operand1 = proc.registerB;

  proc.memory[index] = operand1;
} // StoreB

void StoreJ( GCompProc &proc, uint32_t P1, uint32_t P2 ) {
  int index = P1 + P2;
  uint32_t operand1 = proc.registerJ;

  proc.memory[index] = operand1;
} // StoreJ

void AddMA( GCompProc &proc, uint32_t P1, uint32_t P2 ) {
  //TODO, Correct This
  int index = P1 + P2;
  uint32_t operand1 = proc.memory[index];
  uint32_t operand2 = proc.registerA;

  proc.registerA = operand1 + operand2;
} // AddMA

void AddVA( GCompProc &proc, uint32_t P1, uint32_t P2 ) {
  uint32_t operand1 = P2;
  uint32_t operand2 = proc.registerA;

  proc.registerA = operand1 + operand2;
} // AddVA

void SubMA( GCompProc &proc, uint32_t P1, uint32_t P2 ) {
  //TODO, Correct This
  int index = P1 + P2;
  uint32_t operand1 = proc.memory[index];
  uint32_t operand2 = proc.registerA;

  proc.registerA = operand1 - operand2;
} // SubMA

void SubVA( GCompProc &proc, uint32_t P1, uint32_t P2 ) {
  uint32_t operand1 = P2;
  uint32_t operand2 = proc.registerA;

  proc.registerA = operand1 - operand2;
} // SubVA

void DivM( GCompProc &proc, uint32_t P1, uint32_t P2 ) {
  //TODO, Correct This
  int index = P1 + P2;
  uint32_t operand1 = proc.memory[index];
  uint32_t operand2 = proc.registerA;

  proc.registerA = operand1 / operand2;
  proc.registerB = operand1 % operand2;
} // DivM

void DivV( GCompProc &proc, uint32_t P1, uint32_t P2 ) {
  uint32_t operand1 = P2;
  uint32_t operand2 = proc.registerA;

  proc.registerA = operand1 / operand2;
  proc.registerB = operand1 % operand2;
} // DivV

void MultM( GCompProc &proc, uint32_t P1, uint32_t P2 ) {
  //TODO, Correct This
  int index = P1 + P2;
  uint32_t operand1 = proc.memory[index];
  uint32_t operand2 = proc.registerA;

  proc.registerA = operand1 * operand2;
} // MultM

void MultV( GCompProc &proc, uint32_t P1, uint32_t P2 ) {
  uint32_t operand1 = P2;
  uint32_t operand2 = proc.registerA;

  proc.registerA = operand1 * operand2;
} // MultV

void AndM( GCompProc &proc, uint32_t P1, uint32_t P2 ) {
  //TODO, Correct This
  int index = P1 + P2;
  uint32_t operand1 = proc.memory[index];
  uint32_t operand2 = proc.registerA;

  proc.registerA = operand1 & operand2;
} // AndM

void AndV( GCompProc &proc, uint32_t P1, uint32_t P2 ) {
  uint32_t operand1 = P2;
  uint32_t operand2 = proc.registerA;

  proc.registerA = operand1 & operand2;
} // AndV

void OrM( GCompProc &proc, uint32_t P1, uint32_t P2 ) {
  //TODO, Correct This
  int index = P1 + P2;
  uint32_t operand1 = proc.memory[index];
  uint32_t operand2 = proc.registerA;

  proc.registerA = operand1 | operand2;
} // OrM

void OrV( GCompProc &proc, uint32_t P1, uint32_t P2 ) {
  uint32_t operand1 = P2;
  uint32_t operand2 = proc.registerA;

  proc.registerA = operand1 | operand2;
} // OrV

void Not( GCompProc &proc, uint32_t P1, uint32_t P2 ) {
  uint32_t operand1 = proc.registerA;

  proc.registerA = !operand1;
} // Not

void XorM( GCompProc &proc, uint32_t P1, uint32_t P2 ) {
  //TODO, Correct This
  int index = P1 + P2;
  uint32_t operand1 = proc.memory[index];
  uint32_t operand2 = proc.registerA;

  proc.registerA = operand1 ^ operand2;
} // XorM

void XorV( GCompProc &proc, uint32_t P1, uint32_t P2 ) {
  uint32_t operand1 = P2;
  uint32_t operand2 = proc.registerA;

  proc.registerA = operand1 ^ operand2;
} // XorV

void SftL( GCompProc &proc, uint32_t P1, uint32_t P2 ) {
  uint32_t operand1 = P1;
  uint32_t operand2 = proc.registerA;

  proc.registerA = operand1 << operand2;
} // SftL

void SftLC( GCompProc &proc, uint32_t P1, uint32_t P2 ) {
  uint32_t operand1 = P1;
  uint32_t operand2 = proc.registerA;

  proc.registerA = operand1 << operand2;
} // SftLC

void SftR( GCompProc &proc, uint32_t P1, uint32_t P2 ) {
  uint32_t operand1 = P1;
  uint32_t operand2 = proc.registerA;

  proc.registerA = operand1 >> operand2;
} // SftR

void SftRC( GCompProc &proc, uint32_t P1, uint32_t P2 ) {
  uint32_t operand1 = P1;
  uint32_t operand2 = proc.registerA;

  proc.registerA = operand1 >> operand2;
} // SftRC

void Clr( GCompProc &proc, uint32_t P1, uint32_t P2 ) {
  proc.flags = proc.clear;
} // Clr

void Cmp( GCompProc &proc, uint32_t P1, uint32_t P2 ) {
  uint32_t operand1 = proc.registerA;

  if ( operand1 < 0 )
    proc.flags = proc.lessThan;
  else if ( operand1 > 0 )
    proc.flags = proc.greaterThan;
  else
    proc.flags = proc.equalTo;
} // Cmp

void JmpGT( GCompProc &proc, uint32_t P1, uint32_t P2 ) {
  uint32_t operand1 = P2;
  uint32_t operand2 = proc.registerProgramCounter;
  uint32_t operand3 = proc.flags;

  if ( operand3 == proc.greaterThan ) {
    proc.registerProgramCounter = operand1;
    proc.registerJ = operand2;
  }
} // JmpGT

void JmpET( GCompProc &proc, uint32_t P1, uint32_t P2 ) {
  uint32_t operand1 = P2;
  uint32_t operand2 = proc.registerProgramCounter;
  uint32_t operand3 = proc.flags;

  if ( operand3 == proc.equalTo ) {
    proc.registerProgramCounter = operand1;
    proc.registerJ = operand2;
  }
} // JmpET

void JmpLT( GCompProc &proc, uint32_t P1, uint32_t P2 ) {
  uint32_t operand1 = P2;
  uint32_t operand2 = proc.registerProgramCounter;
  uint32_t operand3 = proc.flags;

  if ( operand3 == proc.lessThan ) {
    proc.registerProgramCounter = operand1;
    proc.registerJ = operand2;
  }
} // JmpLT

void Jmp( GCompProc &proc, uint32_t P1, uint32_t P2 ) {
  uint32_t operand1 = P2;
  uint32_t operand2 = proc.registerProgramCounter;

  proc.registerProgramCounter = operand1;
  proc.registerJ = operand2;
} // Jmp

void Rtn( GCompProc &proc, uint32_t P1, uint32_t P2 ) {
  uint32_t operand1 = proc.registerJ;
  uint32_t operand2 = proc.registerProgramCounter;

  proc.registerProgramCounter = operand1;
  proc.registerJ = operand2;
} // Rtn

void IOClr( GCompProc &proc, uint32_t P1, uint32_t P2 ) {
  if ( P1 == 1 ) {
    scanf("%*s");
  }
} // IOClr

void IOCpy( GCompProc &proc, uint32_t P1, uint32_t P2 ) {
  if ( P1 == 1 ) {
    scanf("%s", proc.memory + P2);
  }
  else if ( P1 == 2 ) {
    printf( "%s", proc.memory + P2);
  }
} // IOCpy

void IOHlt( GCompProc &proc, uint32_t P1, uint32_t P2 ) {
  //Does nothing, due to incomplete timing.
} // IOHlt

void IOJmp( GCompProc &proc, uint32_t P1, uint32_t P2 ) {
  //Does nothing, due to incomplete timing.
} // IOJmp

//method definitions
GCompProc::GCompProc( uint8_t *memory)
  : operations {
  NULL
  , NULL
  , NULL
  , NULL
  , LoadA
  , LoadB
  , LoadJ
  , NULL
  , StoreA   //Op 8
  , StoreB
  , StoreJ
  , NULL
  , NULL
  , NULL
  , NULL
  , NULL
  , AddMA   //Op 16
  , AddVA
  , SubMA
  , SubVA
  , DivM
  , DivV
  , MultM
  , MultV
  , NULL
  , NULL
  , NULL
  , NULL
  , NULL
  , NULL
  , NULL
  , NULL
  , AndM   //Op 32
  , AndV
  , OrM
  , OrV
  , Not
  , XorM
  , XorV
  , SftL
  , SftLC
  , SftR
  , SftRC
  , NULL    //Op 43
  , NULL
  , NULL
  , NULL
  , NULL
  , Clr    //Op 48
  , Cmp
  , JmpGT
  , JmpET
  , JmpLT
  , Jmp
  , Rtn
  , NULL
  , NULL
  , NULL
  , NULL
  , NULL
  , NULL
  , NULL
  , NULL
  , NULL
  , IOClr   //Op 64
  , IOCpy
  , IOHlt
  , IOJmp
}
{
  this->memory = memory;
}

bool GCompProc::ProcessInstruction() {

  //decode instruction into it's components
  printf( "\tByte: %d.\n", registerProgramCounter );

  int opCode = memory[registerProgramCounter];

  printf( "\tByte: %d, value: %d, char value: %c.\n", registerProgramCounter, memory[registerProgramCounter], memory[registerProgramCounter] );
  int parameter1 = memory[registerProgramCounter+3];
  parameter1 = parameter1 << 8;
  parameter1 += memory[registerProgramCounter+2];
  parameter1 = parameter1 << 8;
  parameter1 += memory[registerProgramCounter+1];

  int parameter2 = memory[registerProgramCounter+7];
  parameter2 = parameter2 << 8;
  parameter2 = memory[registerProgramCounter+6];
  parameter2 = parameter2 << 8;
  parameter2 = memory[registerProgramCounter+5];
  parameter2 = parameter2 << 8;
  parameter2 = memory[registerProgramCounter+4];

  printf( "Processing Instruction at %d, opcode: %d, param 1: %d, param 2: %d.\n"
          , registerProgramCounter
          , opCode
          , parameter1
          , parameter2  );

  if ( opCode == 0 )
    return false;

  //pre-compute address offset

  //incriment program counter
  registerProgramCounter += 8; //forward two words

  //process instruction.
  operations[opCode]( *this, parameter1, parameter2 );

  return true;
} // ProcessInstruction

void GCompProc::Reset() {
  registerA = 0;
  registerB = 0;
  registerJ = 0;
  registerProgramCounter = 0;

  flags = clear;

  for ( int index = 0; index < devicesCount; index++ ) {
    devices[index].reset();
  }
} // Reset
