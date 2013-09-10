#pragma once

#include <iostream>

class CircleWalk {
  double x, y;
 public:
 CircleWalk() : x(1), y(0) {}
 CircleWalk(double xx, double yy) : x(xx), y(yy) {}
  friend std::ostream& operator<<(std::ostream&, const CircleWalk&);
  CircleWalk operator*(double) const;
  CircleWalk operator+(const CircleWalk& r) const;
  CircleWalk deriv(double) const;
};
