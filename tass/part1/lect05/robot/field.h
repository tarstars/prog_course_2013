#ifndef _FIELD_
#define _FIELD_

#include <string>

class Robot;

class Field {
  int n;
  std::string dat;
 public:
  Field(int nn);
  char& at(int, int);
  void print(std::ostream&, const Robot&);  
};

#endif
