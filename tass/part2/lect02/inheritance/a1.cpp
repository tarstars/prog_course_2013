#include <iostream>

#include "a1.h"

using namespace std;

int
A1::eval(int x) {
  return 42;
}

A1::~A1() {
  cout << "delete a1" << endl;
}
