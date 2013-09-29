#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
  string val;
  int int_val;
  map<string, int> dat;

  while(cin >> val) {
    ++dat[val];
  }

  for( map<string, int>::iterator it = dat.begin(); it != dat.end(); ++it) {
    cout << it -> first << " -> " << it -> second << endl;
  }
  return 0;
}

/*
  while(cin >> val >> int_val) {
    dat[val] = int_val;
  }
*/
