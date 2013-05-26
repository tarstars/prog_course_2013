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
  PovRayExport dest("lattice.txt");

  for(double x = -5.0; x <= 5.0; x += 1.0)
    for(double y = -5.0; y <= 5.0; y += 1.0)
      for(double z = -5.0; z <= 5.0; z += 1.0)
	dat.push_back( Vec3(x, y, z) );
  
  sort(dat.begin(), dat.end());
  
  vector<Vec3>::const_iterator it = dat.begin();
  
  for( ; it->norm() < 5.0; ) {
    //    cout << "(" << it->x() << "," << it->y() << "," << it->z() << ")" << "  norm : " << it->norm() << endl;
    dest.sphere( Vec3( it->x(), it->y(), it->z() ));
    ++it;
  }

  return 0;
}
