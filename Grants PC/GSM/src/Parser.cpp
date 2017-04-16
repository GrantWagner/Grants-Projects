//file headers

//needed includes
#include "Parser.hpp"
#include <stdlib.h>
#include <string.h>

//Method implementations
Parser::Parser( FILE *filePtr ) {
  this->program = filePtr;

  memset( token, tokenSize * sizeof(char), 0 );
  lineNumber = 0;
  prevLineNumber = 0;
  charNumber = 0;
  prevCharNumber = 0;
  endOfFile = false;

}

Instruction Parser::parseLine() {
  Instruction returnValue;

  //parse characters until end of line or instruction is complete
  while( true ) {

    //read token
    loadToken();
    printf( "First token is %s, prevChar: %d, Char: %d, prevLine: %d, line: %d.\n", token, prevCharNumber, charNumber, prevLineNumber, lineNumber );
    loadToken();
    printf( "Second token is %s, prevChar: %d, Char: %d, prevLine: %d, line: %d.\n", token, prevCharNumber, charNumber, prevLineNumber, lineNumber );
    loadToken();
    printf( "Third token is %s, prevChar: %d, Char: %d, prevLine: %d, line: %d.\n", token, prevCharNumber, charNumber, prevLineNumber, lineNumber );

returnValue.endOfFile = true;
return returnValue;

      //if '@'
        //consume characters until a '>'
        //get filename from string, be careful with filenames with space
        break;
      //elseif '#'
        //consume until a '\n'
        //continue

      //get label and opcode
      //consume until a white space
      //if token ends with a :, set label to token - 1
        //consume token, set opSym = token
      //else set label = "", and opSym = token

      //get parameters
      //consume token
      //if token[size-1] == ','
        //set P1 = token - 1

        //consume token
        //set P2 = token
      // else
        //set P2 = token
        //consume token
        //if ( token[0] == ','
          //rewind to token + 1
        //consume token
        //set P1 = P2
        //set P2 = token

      //we have a full instruction, return it.
  }

  return returnValue;
}

void Parser::loadToken() {
  int index = 0;
  int readChar = 0;
  int currentChar = charNumber;
  int currentLine = lineNumber;

  //consume white space
  while ( true ) {
    if ( feof( program ) == 0 ) {
      readChar = fgetc( program );
      //printf( "Read character %c (%d), expecting white space.\n", readChar, readChar );
      if ( strchr( whiteSpace, readChar ) == NULL ) {
        fseek( program, -1, SEEK_CUR );
        break;
      } else {
        if ( readChar == '\n' ) {
          currentChar = 0;
          currentLine ++;
        } else {
          currentChar ++;
        }
      }
    }
  }

  //consume until white space
  for( index = 0; index < (tokenSize - 1);) {
    //set flag and stop for eof
    if ( feof( program ) != 0 ) {
      endOfFile = true;
      break;
    }

    //read a char
    readChar = fgetc( program );
    //printf( "Read character %c (%d), expecting non-white space.\n", readChar, readChar );

    //if a white space, rewind and break
    if ( strchr( whiteSpace, readChar ) != NULL ) {
      fseek( program, -1, SEEK_CUR );
      break;
    } else {
      //store the character
      currentChar++;
      token[index] = readChar;
      //printf("\tSetting %d to %c (%d).\n", index, readChar, readChar );
      index++;
    }
  }

  //printf("\tSetting %d to %c (%d).\n", index, '\0', '\0' );
  token[index] = '\0';
  prevCharNumber = charNumber;
  prevLineNumber = lineNumber;
  charNumber = currentChar;
  lineNumber = currentLine;


}
