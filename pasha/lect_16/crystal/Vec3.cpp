#include "Vec3.h"
#include <cmath>

Vec3::
~Vec3() {
    delete []vec3;
}

Vec3::Vec3(): vec3(new double[3]()) {}

double
Vec3::at(int i) const{
    return vec3[i];
}

double*
Vec3::get(int i) {
    return vec3 + i;
}
