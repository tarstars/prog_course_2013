#include <iostream>

using namespace std;

int main( void )
{
  for( int b = 1, q = 2; b < 2000; b *= q )
    cout << b << endl;
  
  return 0;
}
