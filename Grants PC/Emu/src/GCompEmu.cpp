//file headers

//needed includes
#include "GCompProc.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <cstdint>

//main function
int main( int argc, char *argv[] ) {

  //Argument check
  if ( argc != 2 ) {
    printf( "Proper command line parameters.\n" );
    printf( "\t%s <filename>\n", argv[0] );
    printf( "\n" );
    return EXIT_SUCCESS;
  }

  //1GB of ram
  //why can't I use a larger memory block?
  const int memSize = 1024 * 1024;
  uint8_t *memory = (uint8_t*)malloc( memSize * sizeof(uint8_t) );
  memset( memory, memSize, sizeof(uint8_t) );
  printf( "Initialized Memory\n" );

  //load the binary code
  FILE *program = NULL;
  program = fopen( argv[1], "rls ");
  if ( program == NULL ) {
    printf( "Could not open file %s.\n", argv[1] );
  }
  fread( memory, sizeof(uint8_t), memSize, program );
  fclose( program );

  printf( "Loaded program.\n" );
  for ( int index = 0; index < 32; index++ ) {
    printf( "\tByte: %d, value: %d, char value: %c.\n", index, memory[index], memory[index] );
  }

  //create the emulator
  printf( "Testing 2.\n" );
  GCompProc processor = GCompProc( memory );

  //process until halted
  printf( "Testing 1.\n" );
  while ( processor.ProcessInstruction() );

  free( memory );
  return EXIT_SUCCESS;
} // main
