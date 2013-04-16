#include <cmath>
#include <iostream>

using namespace std;

void solve_sq(int a, int b, int c) {
  if (a == 0) {
    throw(string("not square equation"));
  }

  int d = b * b - 4 * a * c;
  if (d < 0) {
    throw(string("imaginary roots"));
  }
   
  if (d == 0) {
    throw(100500);
  }

  cout << "x12 = " << (-b + sqrt(d)) / (2 * a) << ", " << (-b - sqrt(d)) / (2 * a) << endl;
}

void interactive_solver() {
  int ans = 0;
  do {
    int a, b, c;
    cout << "a b c => ";
    cin >> a >> b >> c;
    solve_sq(a, b, c);
    cout << "1 for continue => ";
    cin >> ans;
  } while (ans == 1);
}

int main() {
  try {
    interactive_solver();
  } catch(string msg) {
    cout << "error: " << msg << endl;
  }
}

/*
 catch(int msg) {
    cout << "int error: " << msg << endl;
  } catch(...) {
    cout << "universal section" << endl;
    }
*/
