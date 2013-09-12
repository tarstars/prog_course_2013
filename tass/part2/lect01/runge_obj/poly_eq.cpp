#include "poly_eq.h"

using namespace std;

ostream& operator<<(ostream& os, const PolyEq& r) {
  return os << r.val;
}

PolyEq 
PolyEq::deriv(double) const {
  return PolyEq(val*complex<double>(0,1));
}

PolyEq 
PolyEq::operator*(complex<double> r) const {
  return PolyEq(val * r);
}

PolyEq
PolyEq::operator+(const PolyEq& r) const {
  return PolyEq(val + r.val);
}


