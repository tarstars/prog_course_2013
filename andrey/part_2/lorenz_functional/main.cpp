#include <complex>
#include <iostream>
#include <vector>

using namespace std;

vector<complex<double> > init() {
  vector<complex<double> > ret(3);

  ret[0] = 1;
  ret[1] = 1;
  ret[2] = 1 ; 
  return ret;
}

vector<complex<double> > operator*(const vector<complex<double> >& z, 
				   const complex<double>& r) {
  vector<complex<double> > ret(z);

  for(int t = 0; t < (int) z.size(); t++) {
    ret[t] *= r;
  }

  return ret;
}


vector<complex<double> > operator+(const vector<complex<double> >& zl, 
				   const vector<complex<double> >& zr) {
  if (zl.size() != zr.size()) {
    throw(string("operator+: wrong dimensions"));
  }

  vector<complex<double> > ret(zl);

  for(int t = 0; t < (int) zl.size(); t++) {
    ret[t] += zr[t];
  }

  return ret;
}

vector<complex<double> > f(const vector<complex<double> > &zp, double t) {
  vector<complex<double> > ret(zp.size());

  (void)t; 
  double q = 10;
  double rho = 28;
  double beta = 8/3; 
  ret[0] = (zp[1]-zp[0])*q;
  ret[1] = zp[0]*(rho - zp[2]) - zp[1];
   ret[2] = zp[0]*zp[1] - beta*zp[2];
  return ret;
}
vector<complex<double> > one_step(std::vector<std::complex<double> > (*pf)(const std::vector<std::complex<double> >&, double),
				  const vector<complex<double> > &zp, 
				  double dt, 
				  double t) {
  vector<complex<double> > k1 = pf(zp,t) * dt;
  vector<complex<double> > k2 = pf(zp + k1 * 0.5, t + dt/2) * dt;
  vector<complex<double> > k3 = pf(zp + k2 * 0.5, t + dt/2) * dt;
  vector<complex<double> > k4 = pf(zp + k3, t + dt) * dt;

  return zp + (k1 + k2 * 2 + k3 * 2 + k4) * (1.0 / 6);
}
ostream&
operator<<(ostream& os, const vector<complex<double> >& z) {
  for(int i = 0; i < (int)z.size(); i++) {
    os << z[i] << " ";
  }
  return os;
}
void calculation() {

  vector<complex<double> > z =  init();
  
  double dt = 0.01;
  for(double t = 0; t < 20; t += dt) {
    z = one_step(f, z, dt, t);
 
   cout << t << " " << real(z[0]) << " " << real(z[1]) <<" " << real(z[1]) << endl;
 
}
}
int main() {
  try {
    calculation();
  } catch(string msg) {
    cout << "error: " << msg << endl;
  }
}
