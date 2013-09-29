#include <iostream>

#include "field.h"
#include "robot.h"

using namespace std;

int main() {
  Robot bob;
  Field fld(20);

  char c;
  while(cin >> c) {
    switch(c) {
    case 'w': bob.up();break;
    case 's': bob.down();break;
    case 'a': bob.left();break;
    case 'd': bob.right();break;
    }
    fld.print(cout, bob);
  }

  return 0;
}
