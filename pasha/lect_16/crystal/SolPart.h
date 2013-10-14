#pragma once

#include "vec3.h"
#include <iostream>

class SolPart {
    double v;
    Vec3 q;
public:
    SolPart() : v(0), q(Vec3(0,0,0)) {}
    SolPart(double vel, Vec3 pol) : v(vel), q(pol) {}
    friend std:: ostream& operator<<(std::ostream&, const SolPart&);
};
