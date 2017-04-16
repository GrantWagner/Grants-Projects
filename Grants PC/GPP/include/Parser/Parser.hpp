// File header

#ifndef _PARSER_HPP_
#define _PARSER_HPP_

#include <map>
#include <string>
#include <cstdio>
#include <stdlib.h>
#include "./Parser/TOs/Class.hpp"

using namespace std;

map<string, Class> parse(File *input);

#endif
