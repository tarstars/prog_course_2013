#include "ao.h"
#include <complex>

using namespace std;

ostream& operator<<(ostream& os, const AO& c) {
	//return os << abs(c.c0) * abs(c.c0);
	return os << abs(c.c1) * abs(c.c1);
}

AO
AO::operator*(complex<double> r) const {
	return AO(c0*r, c1*r);
}

AO
AO::operator+(const AO& c) const {
	return AO(c0 + c.c0, c1 + c.c1);
}

AO
AO::deriv(double x, double y, double q) const {
	complex<double> i(0,1);  //мнимая единица
	return AO( c1 * (-q/2 * exp(i*y*x)),  c0 * (q/2 * exp(-i*y*x)) );
}