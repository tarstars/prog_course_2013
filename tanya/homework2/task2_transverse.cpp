#include <iostream>
#include <math.h>

using namespace std;

int main() {
  double x,y;
  bool t = true;
  double s = 0;
  int p = 0;
  
  while (cin >> x) {
    if (t) {
      y = x;
      t = false;
    } else {
      s = s * y + x;
      p += 1;
    }
  }
  cout << "sum is " << s << endl;
}
