#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main ()
{

  cout << "I count simple statistics for stin:" << endl;
  cout << "(you can write: './hm_02_1 < data1.txt')" << endl;

  double val, sum = 0, av = 0, dis = 0, n = 0;
  
  while( cin >> val )
    {
      n++;
      sum = sum + val;
      dis = dis + val*val;
      cout << val << " ";
    }

  av = sum/n;
  dis = dis/n-av*av;

  cout << endl;
  cout << "QUANTITY = " << n << endl;
  cout << "SUM = " << sum << endl;
  cout << "MEAN = " << av << endl;  
  cout << "VARIANCE = " << dis << endl;

  return 0;

}
