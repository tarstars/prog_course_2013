#ifndef _FIELD_
#define _FIELD_

#include <string>

class Field {
  int n;
  std::string dat;
 public:
  Field(int nn);
  char& at(int, int);
  
};

#endif
