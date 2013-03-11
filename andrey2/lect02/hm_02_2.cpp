#include <iostream>

using namespace std;

int main ()
{

  cout << "I compute value of polynom and its derivative" << endl;
  cout << "(you can write: './hm_02_1 < data1.txt')" << endl;
  cout << "format: x a[n] a[n-1] .. a[1] a[0]" << endl;

  double x, ai = 0, val = 0, der1 = 0, der2 = 0;
  
  cin >> x;
  while( cin >> ai )
    {
      val = val*x+ai;
      der1 = der1*x+der2;
      der2 = der2*x+ai;
    }

  cout << endl;
  cout << "VALUE = " << val << endl;
  cout << "DERIVATIVE = " << der1 << endl;

  return 0;

}
