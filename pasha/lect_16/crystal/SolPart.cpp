#include "SolPart.h"
#include <cmath>

SolPart::
~SolPart() {
    delete []sol;
}

SolPart::SolPart(): sol(new double[2]()) {}

double
SolPart::at(int i) const{
    return sol[i];
}

double*
SolPart::get(int i) {
    return sol + i;
}
