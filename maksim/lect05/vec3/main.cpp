#include "vec3.h"

using namespace std;

int main() {
  Vec3 X(1, 5, 4);

  cout << "Print vector X: X =" << X << endl;

  cout << "Operation []: X[2] = " << X[2] << endl;

  cout << " |X| = " << X.length() << endl;

  Vec3 Y;
  Y = X*2;
  cout << "Y = X*2 =" << Y << endl;

  cout << "X + Y =" << X + Y << endl;
  cout << "X - Y =" << X - Y << endl;

  cout << "3*X = " << 3*X << endl;
  return 0;
}
