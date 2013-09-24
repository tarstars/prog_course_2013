#pragma once
#include <iostream>
class Circlewalk {
  double x,y,z;
 public:
 Circlewalk():x(1),y(1),z(1) {}
 Circlewalk(double xx, double yy,double zz):x(xx),y(yy),z(zz){}
 Circlewalk operator*(double) const;
 Circlewalk operator+(const Circlewalk& r) const;
 friend std::ostream& operator<<(std::ostream&, const Circlewalk&);
 Circlewalk deriv(double) const;
};
