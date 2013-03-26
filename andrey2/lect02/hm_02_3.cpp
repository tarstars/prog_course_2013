#include <iostream>

using namespace std;

int main ()
{

  cout << "Algoritm Evklida" << endl;
  cout << "Input 2 numbers" << endl;

  int x, y;
  
  cin >> x >> y;
  
  while( x > 0 )
  {
      if( y > x )
      {
	swap(x,y);
      }
      x = x-y;
  }

  cout << "NOD(x,y) = " << x+y << endl;

  return 0;

}
