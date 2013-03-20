#include "3vector.h"

3vector::3vector(): x(0), y(0), z(0) {}

3vector::3vector(double a, double b, double c): x(a), y(b), z(c) {}

ostream&
operator<< (ostream &os, const 3vector &r) {
	return os << "(" << r.x << ", "<< r.y << ", "<<r.z;
}

double& at(int i) {
	switch(i) {
		case "1": return &x; break;
		case "2": return &y; break;
		case "3": return &z; break;
	}
}

3vector&
3vector::operator* (double a) {
	return 3vector(x*a, y*a, z*a);
}

3vector&
3vector::operator+ (const 3vector& t) const {
	return 3vector(x+t.x, y+t.y, z+t.z);
}