#include <iostream>

#include "circle_walk.h"
#include "poly_eq.h"

using namespace std;

template <typename T>
T one_step( const T &zp, double dt, double t) {

  T k1 = zp.deriv(t) * dt;
  T k2 = (zp + k1 * 0.5).deriv(t + dt / 2) * dt;
  T k3 = (zp + k2 * 0.5).deriv(t + dt / 2) * dt;
  T k4 = (zp + k3).deriv(t + dt) * dt;

  return zp + (k1 + k2 * 2 + k3 * 2 + k4) * (1.0 / 6);
}

int main(int argc, char ** argv) {
  double dt = 0.1;
  PolyEq z;
  for(double t = 0; t < 6.3; t += dt) {
    z = one_step(z, dt, t);
    cout << t << " " << z << endl;
  }
}
