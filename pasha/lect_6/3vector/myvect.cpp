#include "myvect.h"

myvect::myvect(): x(0), y(0), z(0) {}

myvect::myvect(double a, double b, double c): x(a), y(b), z(c) {}

ostream&
operator<< (ostream& os, const myvect& r) {
	return os << "(" << r.x << ", "<< r.y << ", "<<r.z;
}

/*double 
operator_ (const myvect r, int i) {
	if(i==1) {return r.x;}
	if(i==2) {return r.y;}
	if(i==3) {return r.z;}
}*/

myvect
operator* (const myvect r, double a) {
	myvect q(r.x*a, r.y*a, r.z*a);
	return q;
}

myvect
operator+ (const myvect l, const myvect r) {
	myvect q(l.x+r.x, l.y+r.y, l.z+r.z);
	return q;
}
