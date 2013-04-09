#include <iostream>

using namespace std;

int main ( ) {
  double x, a; 
  double plnm = 0, drv = 0;
  
  cin >> x;
  while( cin >> a ) {
    plnm = a + plnm*x;
    drv = drv*x + (plnm - a)/x ;
  }
  cout << "the polinom at x = " << x << " equals " << plnm << endl;
  cout << "the derivative equals " << drv << endl;
  return 0;
}
