#include <iostream>
#include <cmath>

#include "vec3.h"

using namespace std;

Vec3::Vec3() {
    dat[0] = 0;
    dat[1] = 0;
    dat[2] = 0;
}

Vec3::Vec3(double a, double b, double c) {
    dat[0] = a;
    dat[1] = b;
    dat[2] = c;
}

Vec3 Vec3::normalized() {
    double norm =sqrt(
                dat[0]*dat[0] + dat[1]*dat[1] + dat[2]*dat[2]);
    for(int i=0; i<3; ++i) {
        dat[i] = dat[i] / norm;
    }
    return *this;
}

double
Vec3::abs() {
    double norm =sqrt(
                dat[0]*dat[0] + dat[1]*dat[1] + dat[2]*dat[2]);
    return norm;
}

void
Vec3::set(int ind, double val) {
    dat[ind] = val;
}

double
Vec3::at(int ind) const {
    return dat[ind];
}

ostream& operator << (ostream& os, const Vec3& r) {
    return os << r.dat[0] << " " << r.dat[1] << " " << r.dat[2];
}
