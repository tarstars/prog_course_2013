#include <iostream>

using namespace std;

int bin_euclid( int , int );

int main() {
  int a, b;
  cout << "Enter int a : " << endl;
  cin >> a;
  cout << "Enter int b : " << endl;
  cin >> b;

  cout << "gcd : " << bin_euclid( a, b) << endl;
   
  return 0;
}

int bin_euclid( int a, int b )
{
  int d = 1;
  while ( true )
    {
      if( a == 0 || b == 0 ) { if ( a==0 ) d = b; else d = a; break; }
      if( a%2 == 0 && b%2 == 0 ) { 
	a = a/2; b = b/2;
	continue; 
      }
      if( a%2 == 0 && b%2 == 1 ) { 
	a = a/2; 
	continue; 
      }
      if( a%2 == 1 && b%2 == 0 )  { 
	  b = b/2; 
	  continue; 
	}
      if( a%2 == 1 && b%2 == 1 ) { 
	if( a > b ) a = a - b; 
	else b = b - a; 
	}
    }
  return d;
}
