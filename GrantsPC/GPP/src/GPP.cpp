//file headers

//needed includes
#include <cstdio>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <cstdint>
#include <map>
#include "Parser/Parser.hpp"

using namespace std;

//main function
int main( int argc, char *argv[] ) {

  //Argument check
  if ( argc != 2 ) {
    printf( "Proper command line parameters.\n" );
    printf( "\t%s <filename>\n", argv[0] );
    printf( "\n" );
    return EXIT_SUCCESS;
  }

  //scan for code files.
  //For each file
  FILE *program = NULL;
  program = fopen( argv[1], "rls ");
  if ( program == NULL ) {
    printf( "Could not open file %s.\n", argv[1] );
  }

  map<string, Class> classes = parse( program);
  fclose( program );
  //}

  //~ checkSementics(classes);
  //~ optimise(classes);
  //~ ByteArray machineCode = generateExe(classes)
  //~ optimise(machineCode);

  //write machine code
  //

  return EXIT_SUCCESS;
} // main
