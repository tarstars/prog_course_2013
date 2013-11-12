#include "SolPart.h"
#include <iostream>

using namespace std;

ostream& operator<<(ostream& os,const SolPart& sol) {
    os << "v = " << sol.v << endl;
    os << "q = "<< sol.q;
    return os;
}

void
SolPart::put(double vv, Vec3 qq) {
  v = vv;
  q = qq;
}

double
SolPart::get_v() const {
    return v;
}

double
SolPart::get_q() const {
    return q;
}
