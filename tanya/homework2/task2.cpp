#include <iostream>
#include <cmath>

using namespace std;

int main (){
  double x,y;
  double s = 0;
  double g = 0;
  int p = 0; 
  bool t = true;
 
  while (cin >> x) {
    if (t) {
      y = x;
      t = false;
    } else {
      s += pow(y,p)*x;
      g += p*pow(y,p-1)*x;
      p += 1;    
    }
  }

  cout << "sum is " << s << endl;
  cout << "derivation is " << g << endl;
}
