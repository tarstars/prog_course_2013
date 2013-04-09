#ifndef _VEC3_
#define _VEC3_
#include <iostream>
#include <vector>

class Vec3 {
  std::vector<double> v;
public:
  Vec3() {}
  Vec3( double x, double y, double z);
  double operator [] ( int );
  double length();
  friend std::ostream& operator <<( std::ostream&, const Vec3& );
  friend Vec3 operator *(double, const Vec3&);
  Vec3 operator *( double );
  Vec3 operator +( const Vec3& );
  Vec3 operator -( const Vec3& );
};

#endif
