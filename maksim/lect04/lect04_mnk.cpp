#include <iostream>

using namespace std;

int main() {
  int n = 0;
  double x, y, A = 0, B = 0, C = 0, D = 0;
  while ( cin >> x >> y ) {
    n += 1;
    A += x; 
    B += y;
    C += x*x ;
    D += x*y ;
  }
  double k, c;
  k = ( n*D - A*B )/( n*C - A*A );
  c = ( C*B - A*D )/( n*C - A*A );
  cout << " k = " << k << " , c = " << c << endl;
  
  return 0;
}
