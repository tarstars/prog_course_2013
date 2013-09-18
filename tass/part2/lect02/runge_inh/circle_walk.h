#pragma once

#include <iostream>

#include "solvable.h"

class CircleWalk : public Solvable {
  double x, y;
 public:
  CircleWalk();
  CircleWalk(double xx, double yy);
  friend std::ostream& operator<<(std::ostream&, const CircleWalk&);
  CircleWalk operator*(double) const;
  CircleWalk operator+(const CircleWalk& r) const;
  CircleWalk deriv(double) const;

  Solvable* mult(double);
  Solvable* add(Solvable*);
  Solvable* derive();
  Solvable* Clone();
  void Print(std::ostream&);
};
