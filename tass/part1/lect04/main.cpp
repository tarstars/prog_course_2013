#include <cmath>
#include <iostream>

using namespace std;

class Complex {
  double x, y;
public:
  Complex() : x(0), y(0) {}
  Complex(double x, double y) {
    this -> x = x;
    this -> y = y;
  }

  double abs() {return sqrt(x * x + y * y);}

  void print(ostream& os) {os << "(" << x << ", " << y << ")";}
  //friend ostream& operator<<(ostream&, const Complex&);
  ostream& operator>>(ostream& os) const {
    return os << "(" << x << ", " << y << ")";
  }

  Complex operator+(const Complex& r)  {
    return Complex(x + r.x, y + r.y);
  }
};

ostream& operator<<(ostream& os, const Complex& r) {
  return r >> os;
}

// ostream&
// operator<<(ostream& os, const Complex& r) {
//   return os << "(" << r.x << ", " << r.y << ")"; 
// }

int main() {
  Complex alpha(3, 4), beta(10, 20);
  Complex gamma;
  const Complex& delta = beta;
  
  alpha.print(cout);
  //cout << alpha;
  //operator<<(cout, alpha);
  alpha.operator>>(cout);
  cout << "when alpha = " << alpha << " the weather is good" << endl ;
  
  gamma = alpha.operator+(beta);
  gamma = delta + alpha;
  cout << alpha << " + " << beta << " = " << gamma << endl;
}
