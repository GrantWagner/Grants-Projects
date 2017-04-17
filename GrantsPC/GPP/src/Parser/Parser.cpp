//File header

#include "Parser/Tokenizer.hpp"

ClassMap parse(File *input) {
  Tokenizer tokenizer = new Tokenizer(input)
  StringList warnings = new StringList();
  StringList errors = new StringList();
  ClassMap classes = new ClassMap();

  while (tokenizer->hasMore()) {
    Class currentClass = parseClass(tokenizer, warnings, errors);
    classes.add(currentClass.name, currentClass);
  }

  return classes;
}
