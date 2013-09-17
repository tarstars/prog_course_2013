#include "circlewalk.h"
#include <complex>

using namespace std;

circlewalk::circlewalk() : x(1), y(0) {}

circlewalk::circlewalk(double xx, double yy) : x(xx), y(yy) {}

ostream& operator<<(ostream& os, const circlewalk& r) {
	return os << r.x << " " << r.y;
}

circlewalk
circlewalk::operator*(double r) const {
	return circlewalk(x*r, y*r);
}

circlewalk
circlewalk::operator+(const circlewalk& r) const {
	return circlewalk(x + r.x, y + r.y);
}

circlewalk
circlewalk::deriv(double) const {
	return circlewalk(-y, x);
}


Solvable*
circlewalk::mult(double r) {
	x *= r;
	y *= r;
	return this;
}

Solvable*
circlewalk::add(Solvable* p) {
	x += dynamic_cast<circlewalk*>(p) -> x;
	y += dynamic_cast<circlewalk*>(p) -> y;
	return this;
}

Solvable*
circlewalk::derive() {
	double tx = x, ty = y;
	x = -ty;
	y = -tx;
	return this;
}

Solvable*
circlewalk::clone() {
	return new circlewalk(*this);
}

void
circlewalk::print(ostream& os) {
	os << x << " " << y << endl;
}