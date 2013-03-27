#include <iostream>

using namespace std;

int main ( ) {
  int i = 0;
  double x, z, v = 1;
  double polinom = 0, derivative = 0;
  
  cin >> x;
  while( cin >> z ) {
    if( i == 0) { polinom += z; cout << polinom << endl; }
    else { 
      derivative += i*z*v ;
      v *= x;
      polinom += z*v;
      cout << polinom << endl;
    }
    i++;
  }
  cout << "the polinom at x = " << x << " equals " << polinom << endl;
  cout << "the derivative equals " << derivative << endl;
  return 0;
}
