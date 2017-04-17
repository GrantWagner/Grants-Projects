
//file header

//header safeguards
#ifndef _PARSER_HPP_
#define _PARSER_HPP_

//needed includes
#include "Instruction.hpp"
#include <cstdint>
#include <stdio.h>

using namespace std;

class Parser {
public:
  Parser( FILE *filePtr );
  Instruction parseLine();
  void loadToken();


private:
  const char *whiteSpace = " \t\n";
  static const int tokenSize = 255;
  char token[tokenSize];

  int lineNumber;
  int prevLineNumber;
  int charNumber;
  int prevCharNumber;
  bool endOfFile;

  FILE *program;
};

//more headersafeguards
#endif
