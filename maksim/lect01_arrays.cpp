#include <iostream>

using namespace std;

void print(int*, int*);

void next(int*, int*);

int main()
{
  const int n = 5;
  const int k = 3;
  int a[n+k];
  
  for( int i = 0; i < n; i++ ) a[i] = 0;
  for( int i = n; i < n+k ; i++ ) a[i] = 1;
 
  next( a, a+n+k );
  print( a, a+n+k );
  next( a, a+n+k );
  print( a, a+n+k );

  return 0;
}

void print(int* begin, int* end)
{
  int *p = begin;
  for( ; p != end; ++p )
    cout << *p ;
  cout << endl;
}

void next(int* begin, int* end)
{
}
