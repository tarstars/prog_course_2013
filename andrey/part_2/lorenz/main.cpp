#include <iostream>
#include "lorenz.h"
using namespace std;
Circlewalk onestep(const Circlewalk &zp, double dt, double t){
  Circlewalk k1 = zp.deriv(t)*dt;
  Circlewalk k2 = (zp + k1*0.5).deriv(t+dt/2)*dt;
  Circlewalk k3 = (zp + k2*0.5).deriv(t+dt/2)*dt;
  Circlewalk k4 = (zp + k3).deriv(t+dt)*dt;

  return zp + (k1+ k2*2 + k3*2 + k4)*(1.0/6);
}
int main(int argc, char ** argv){
  double dt = 0.1;
  Circlewalk z;
  for(double t=0;t<1; t+=dt){
    z = onestep(z,dt,t);
    cout<<z<<endl;
}
}
