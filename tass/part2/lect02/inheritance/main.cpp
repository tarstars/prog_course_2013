#include <iostream>

#include "a.h"
#include "a1.h"
#include "a2.h"

using namespace std;

int main() {
  A* pworker;

  int c;
  cin >> c;
  if (c == 0) 
    pworker = new A1;
  else 
    pworker = new A2;

  cout << "a:" << pworker->eval(1) << endl;

  delete pworker;
}
