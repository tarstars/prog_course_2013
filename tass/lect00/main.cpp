#include <iostream>

using namespace std;

int main() {
  int a = 5;
  int &b =a;
  int &x = b;

  cout << "a = " << a << endl;
  cout << "b = " << b << endl;
  cout << "x = " << x << endl;
  cout << endl;

  x=111;
  cout << "a = " << a << endl;
  cout << "b = " << b << endl;
  cout << "x = " << x << endl;
  cout << endl;
}
