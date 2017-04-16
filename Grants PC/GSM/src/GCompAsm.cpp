//file headers

//needed includes
#include "GCompProc.hpp"
#include "Instruction.hpp"
#include "Parser.hpp"
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

  //load the asm file
  FILE *program = NULL;
  program = fopen( argv[1], "rls ");
  if ( program == NULL ) {
    printf( "Could not open file %s.\n", argv[1] );
    return EXIT_SUCCESS;
  }

  Parser parser(program);

  //Run Parser
  while ( true ) {
    //For each line
    Instruction inst = parser.parseLine();

    if ( inst.endOfFile ) {
      break;
    }

    //If empty list, continue
    if ( inst.opCode == noOp ) {
      continue;
    }

    //Build Machine language string
  }


  fclose( program );
  printf( "Loaded program.\n" );

  return EXIT_SUCCESS;
} // main
