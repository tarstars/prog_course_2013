#pragma once
#include "vec3.h"
class SolPart{
  double v;
  Vec3 q;
public:
  SolPart(){}
  //  SolPart(double x, double y, double z) : q(x, y, z) {}
 SolPart(double vv, Vec3 qq): v(vv), q(qq) {}
  void Put(double vv, Vec3 qq){ 
    v = vv;
    q = qq;
  }

  friend std::ostream& operator<<(std::ostream&, const SolPart& r);
};
