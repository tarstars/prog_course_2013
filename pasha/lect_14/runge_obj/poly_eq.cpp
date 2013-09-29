#include "poly_eq.h"

using namespace std;

ostream& operator<<(ostream& os, const PolyEq& r) {
	return os << r.val;
}

PolyEq
PolyEq::operator*(double r) const {
	return PolyEq(val*r);
}

PolyEq
PolyEq::operator+(const PolyEq& r) const {
	return PolyEq(val + r.val);
}

PolyEq
PolyEq::deriv(double) const {
	return PolyEq(val*val);
}