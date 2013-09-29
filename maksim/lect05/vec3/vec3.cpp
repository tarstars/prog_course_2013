#include <iostream>
#include <cmath>
#include "vec3.h"

using namespace std;

Vec3::Vec3(double x, double y, double z): v(3) {
  v[0] = x; v[1] = y; v[2] = z;
}

double Vec3::operator [] (int i) {
  return v[i-1];
}

double Vec3::length() {
  double l = 0;
  for(int i = 0; i < (int)v.size(); i++) l += v[i]*v[i];
  return sqrt(l);
}

ostream& operator <<( ostream& os, const Vec3& V) {
  os << " ( ";
  for(int i = 0; i < (int)V.v.size()-1; i++) os << V.v[i] << " , ";
  os << V.v[V.v.size()-1] <<  " ) ";
  return os;
} 

Vec3 operator * ( double k, const Vec3& V) {
  return Vec3( k* V.v[0], k * V.v[1], k * V.v[2] );
}

Vec3 Vec3::operator *( double k) { 
  return Vec3( k*v[0], k*v[1], k*v[2] );;
}

Vec3 Vec3::operator +( const Vec3& V ) {
  return Vec3( v[0] + V.v[0], v[1] + V.v[1], v[2] + V.v[2] );
}

Vec3 Vec3::operator -( const Vec3& V ) {
  return Vec3( v[0] - V.v[0], v[1] - V.v[1], v[2] - V.v[2] );
}
