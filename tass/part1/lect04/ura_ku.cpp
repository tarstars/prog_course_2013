#include <iostream>

using namespace std;

int main() {
  #ifdef KU
  cout << "ku" << endl;
  #endif

  #ifdef URA
  cout << "ura!" << endl;
  #endif
}
