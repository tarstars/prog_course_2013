#include <iostream>

using namespace std;

int main () {
  double x;
  double a = 0;
  double b = 0;
  int n = 0;

  while(cin >> x) {
    cout << x << " ";
    a += x;
    b += x * x;
    n += 1;
  }
  
  double d = b/n - (a/n) * (a/n);
  cout << "sum is " << a << endl;
  cout << "nubmer of elements is " << n << endl; 
  cout << "dispersion is " <<  d << endl;

  return 0;
}
