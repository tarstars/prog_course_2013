#include <algorithm>
#include <cmath>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Vec3 {
  double dat[3];
public:
  Vec3(double x, double y, double z) {
    dat[0] = x;
    dat[1] = y;
    dat[2] = z;
  }
  double& x() {return dat[0];}
  double& y() {return dat[1];}
  double& z() {return dat[2];}

  const double& x() const {return dat[0];}
  const double& y() const {return dat[1];}
  const double& z() const {return dat[2];}

  double norm() const {
    return x() * x() + y() * y() + z() * z();
  }

  bool operator< (const Vec3& r) const {
    return norm() < r.norm() - 1e-8;
  }
  
};


class PovRayExport {
  ofstream dest;
public:
  PovRayExport(string flnm) :dest(flnm.c_str()) {
    dest << "#version 3.7;\n"
      "\n"
      "global_settings {assumed_gamma 1.0}\n"
      "\n"
      "#declare dist = 10;\n"
      "\n"
      "camera {\n"
      "  location <dist * cos(2 * pi * clock), 7, dist * sin( 2 * pi * clock)>\n"
      "  look_at <0, 0, 0>\n"
      "  angle 30\n"
      "}\n"
      "\n"
      "light_source {\n"
      "  <5, 10, 5>\n"
      "  color <1, 1, 1>\n"
      "}\n";
  }

  void sphere(const Vec3& r) {
    dest << "sphere{ <" << r.x() << ", " << r.z() << ", " << r.y() << "> .1 pigment {color<1,1,1>}}" << endl;
  }
  
};


int main() {
  vector<Vec3> dat;
sort(dat.begin(), dat.end());

  PovRayExport dest("a.pov");

  for(double x = -1; x <= 1.0; x += 0.01) {
    for(double y = -1; y <= 1.0; y += 0.01) {
      if (x * x + y * y < 1) {
	double z = sqrt(1 - x * x - y * y);
	dest.sphere(Vec3(x, y,  z));
	dest.sphere(Vec3(x, y, -z));
      }
    }
  }
}
