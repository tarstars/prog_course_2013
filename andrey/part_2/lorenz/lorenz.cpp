#include "lorenz.h"

using namespace std;

ostream& operator<<(ostream& os,const Circlewalk& r){
  return os<<r.x<<' '<<r.y<<' '<<r.z;
}

Circlewalk
  Circlewalk::deriv(double) const{
  double q =10;
  double  rho = 28;
  double  beta = 8/3; 
  return Circlewalk((y-x)*q,x*(rho-z)-y,x*y - beta*z);
  }

Circlewalk
Circlewalk::operator*(double r) const{
  return Circlewalk(x*r,y*r,z*r);
}

Circlewalk
Circlewalk::operator+(const Circlewalk& r) const{
  return Circlewalk(x + r.x,y + r.y,z + r.z);
}
