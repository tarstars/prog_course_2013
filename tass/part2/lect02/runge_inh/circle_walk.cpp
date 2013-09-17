#include <complex>

#include "circle_walk.h"

using namespace std;

ostream& operator<<(ostream& os, const CircleWalk& r) {
  return os << r.x << " " << r.y;
}

CircleWalk::CircleWalk() : x(1), y(0) 
{}

CircleWalk::CircleWalk(double xx, double yy) : x(xx), y(yy) {}

CircleWalk 
CircleWalk::deriv(double) const {
  return CircleWalk(-y, x);
}

CircleWalk 
CircleWalk::operator*(double r) const {
  return CircleWalk(x * r, y * r);
}

CircleWalk
CircleWalk::operator+(const CircleWalk& r) const {
  return CircleWalk(x + r.x, y + r.y);
}

Solvable* 
CircleWalk::mult(double r) {
  x *= r; 
  y *= r; 

  return this;
}

Solvable*
CircleWalk::add(Solvable* p) {
  x += dynamic_cast<CircleWalk*>(p) -> x;
  y += dynamic_cast<CircleWalk*>(p) -> y; 

  return this;
}

Solvable*
CircleWalk::derive() {
  double tx = x, ty = y;
  x = -ty;
  y = tx;

  return this;
}

Solvable* 
CircleWalk::Clone() {
  return new CircleWalk(*this);
}

void
CircleWalk::Print(ostream& os) {
  os << x << " " << y << endl;
}
