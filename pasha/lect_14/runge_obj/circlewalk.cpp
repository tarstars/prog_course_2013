#include "circlewalk.h"

using namespace std;

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