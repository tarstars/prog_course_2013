#include <iostream>
#include <math.h>

using namespace std;

int main() {

  double x;
  double square = 0, sum = 0, average, dispersion;
  int n = 0;

  while(cin >> x) 
    {
      ++n;
      sum += x;
      square += x*x;
    }
  average = sum / n;
  dispersion = sqrt( ( square - n*average*average )/n );
  cout << "Sum : " << sum << endl;
  cout << "Numbers : " << n << endl;
  cout << "Average : " << average << endl;
  cout << "Dispersion " << dispersion << endl;

  return 0;
}
