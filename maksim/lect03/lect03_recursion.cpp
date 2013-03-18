#include <iostream>

using namespace std;

int factorial(int);
int fibonacci(int);
int C_n_k( int, int);
void HanoiTower(int, int, int);

int main() {

  cout << endl << " Part 1: Factorial : " << endl;
  int n = 0, f; 
  while( 1 ) // show factorials less than 1000000
    {
      f = factorial(n);
      if( f < 1000000 ) {
	cout << n << " : " << f << endl;
	n++;
      }
      else break; 
    }

  cout << endl << " Part 2: Fibonacci : " << endl;
  for( n = 0, f = 0; ; n++) {
    f = fibonacci( n );
    if( f > 1000000 ) break;
    else { cout << f << " " ; if ( n % 10 == 0 && n > 0 ) cout << endl; }
  }
  cout << endl;

  cout << " Part 3: Binomial coefficients : " << endl;

  for( n = 0; n <=5 ; n++ ) {
    for(int k = 0; k <= n; k++ ) {
      cout << C_n_k( n, k ) << " " ;
      if ( k == n ) cout << endl;
    }
  }

  cout << endl << " Part 4: Hanoi Tower : " << endl;
  HanoiTower( 1, 3, 3);

  return 0;
}

int factorial(int n)
{
  if ( n == 0 ) return 1;
  if ( n > 0) return n * factorial(n-1);
}

int fibonacci(int n)
{
  if ( n == 0 ) return 0;
  if ( n == 1 ) return 1;
  if ( n > 1 ) return fibonacci( n - 1 ) + fibonacci( n - 2 );
} 

int C_n_k( int n, int k)
{
  if( k == 0 ) return 1;
  else if( k == n ) return 1;
  else return C_n_k( n - 1, k - 1) + C_n_k( n - 1, k );
}

void HanoiTower( int alpha, int beta, int n)
{
  if( n == 1 ) cout << alpha << "-->" << beta << endl;
  else {
    HanoiTower( alpha, 6 - alpha - beta, n - 1 );
    HanoiTower( alpha, beta, 1);
    HanoiTower( 6 - alpha - beta, beta, n - 1 );
  }
}
