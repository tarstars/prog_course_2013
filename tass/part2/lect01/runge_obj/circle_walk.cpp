#include "circle_walk.h"

using namespace std;

ostream& operator<<(ostream& os, const CircleWalk& r) {
  return os << r.x << " " << r.y;
}

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


