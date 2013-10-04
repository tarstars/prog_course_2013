#include <iostream>

#include "vec3.h"

using namespace std;

Vec3::Vec3() {}

Vec3::Vec3(double a, double b, double c) {
  dat[0] = a;
  dat[1] = b; 
  dat[2] = c;
}

void
Vec3::set(int ind, double val) {
  dat[ind] = val;
}

double
Vec3::at(int ind) const {
  return dat[ind];
}

ostream& operator << (ostream& os, const Vec3& r) {
  return os << r.dat[0] << " " << r.dat[1] << " " << r.dat[2];  
}
