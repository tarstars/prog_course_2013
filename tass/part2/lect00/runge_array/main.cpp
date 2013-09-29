#include <complex>
#include <iostream>
#include <vector>

using namespace std;

vector<complex<double> > init1() {
  vector<complex<double> > ret(2);

  ret[0] = 1;
  ret[1] = 0;

  return ret;
}

vector<complex<double> > init2() {
  vector<complex<double> > ret(1);

  ret[0] = 1;

  return ret;
}
    
vector<complex<double> > f1(const vector<complex<double> > &zp, double t) {
  vector<complex<double> > ret(zp.size());

  (void)t; 

  ret[0] = -zp[1];
  ret[1] = zp[0];

  return ret;
}

vector<complex<double> > f2(const vector<complex<double> > &zp, double t) {
  vector<complex<double> > ret(zp.size());

  (void)t;

  ret[0] = zp[0];

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

  cout << "function number =>";
  int fn; 
  cin >> fn;

  vector<complex<double> > z = (fn == 0) ? init1() : init2();
  
  double dt = 0.1;
  for(double t = 0; t < 1; t += dt) {
    z = one_step((fn == 0) ? f1 : f2, z, dt, t);
    if (fn == 0) {
      cout << t << " " << real(z[0]) << " " << real(z[1]) << endl;
    } else {
      cout << t << " " << real(z[0]) << endl;
    }
  }
}

int main() {
  try {
    calculation();
  } catch(string msg) {
    cout << "error: " << msg << endl;
  }
}
