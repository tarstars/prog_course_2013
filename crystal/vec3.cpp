#include "vec3.h"

#include <cmath>
#include <iostream>

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

double 
Vec3::abs() const {
  return sqrt(dat[0]*dat[0] + dat[1]*dat[1] + dat[2]*dat[2]);
}

Vec3 
Vec3::normalized() const
{
  double length = abs();

  if(length == 0) {
    throw(string("Vec3::normalized zero Vec3"));
  } 

  return Vec3(dat[0]/length, dat[1]/length, dat[2]/length);
}

void 
Vec3::normalize()
{
  double length = abs();

  if(length == 0) {
    throw(string("Vec3::normalized zero Vec3"));
  } 

  dat[0] /= length;
  dat[1] /= length;
  dat[2] /= length;
}	
