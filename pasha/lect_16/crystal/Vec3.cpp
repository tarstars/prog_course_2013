#include <iostream>
#include <cmath>

using namespace std;

#include "vec3.h"

using namespace std;

Vec3::Vec3() {
    dat[0] = 0;
    dat[1] = 0;
    dat[2] = 0;
}

Vec3::Vec3(double a, double b, double c) {
    dat[0] = a;
    dat[1] = b;
    dat[2] = c;
}

double
Vec3::abs() const {
    return sqrt(dat[0]*dat[0] + dat[1]*dat[1] + dat[2]*dat[2]);
}

void
Vec3::normalize() {
    double norm = abs();
    if(norm != 0) {
        dat[0] /= norm;
        dat[1] /= norm;
        dat[2] /= norm;
    }
}

Vec3
Vec3::normalized() const {
  double norm = abs();
  if(norm == 0)
      return Vec3(0,0,0);
  else
      return Vec3(dat[0]/norm, dat[1]/norm, dat[2]/norm);
}

void
Vec3::set(int ind, double val) {
    dat[ind] = val;
}

double
Vec3::at(int ind) const {
    return dat[ind];
}

ostream& operator<< (ostream& os, const Vec3& r) {
    return os << r.dat[0] << " " << r.dat[1] << " " << r.dat[2];
}

Vec3
Vec3::operator* (const Vec3& v) const {
    return Vec3(dat[1]*v.at(2) - dat[2]*v.at(1),
                dat[2]*v.at(0) - dat[0]*v.at(2),
                dat[0]*v.at(1) - dat[1]*v.at(0));
}
