#include <iostream>
using namespace std;
int main() {
  int a,b,c;
  cout << "a=";
  cin >> a ;
  cout << endl << "b=";
  cin >> b;
  cout << endl;
  for (c = a % b; c!=0; a = b, b = c, c = a % b){
    //  cout << a << " " << b << " " << c << endl;
  }
  cout << "NOD=" << b << endl;
}
