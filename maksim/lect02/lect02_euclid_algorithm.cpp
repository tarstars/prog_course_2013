#include <iostream>

using namespace std;

int EGCD(int, int, int&, int&);

int main() {
  int m, n;
  cout << "Enter a integer : " << endl; 
  cin >> m;
  cout << "Enter a integer : " << endl;
  cin >> n;
  cout << m << " " << n << " ";
  int p, q;

  cout << "Greatest common divisor is " << EGCD( m, n, p, q) << endl;
  cout << " p * m + q *n = d " << endl;
  cout << p << "*" << m << " + " << q << "*" << n << " = "
       << EGCD( m, n, p, q) << endl; 
  return 0;
}

int EGCD(int m, int n, int& a, int& b)
{
  int v, w;
  int r, c, z, d;

  // Initializing :
  v = b = 1; 
  a = w = 0;
  c = m; 
  d = n;
  while ( true ) {
    // Division :
    z = c/d ;
    r = c%d ;
    // Does remainder equal zero?
    if ( r == 0 ) { return d; }
    // Recycle :
    c = d; d = r; int t = v; v = a; a = t - z*a; t = w; w = b; b = t - z*b;
  }
}
