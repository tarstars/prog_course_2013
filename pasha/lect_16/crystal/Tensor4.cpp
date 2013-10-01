#include "Tensor4.h"

Tensor4::
~Tensor4() {
    delete []tens;
}

Tensor4::Tensor4(): tens(new double[81]()) {}

double*
Tensor4::set(int i, int j, int k, int l) {
    return tens + j + 3*i + 9*k + 27*l;
}

double
Tensor4::at(int i, int j, int k, int l) const{
    return tens[j + 3*i + 9*k + 27*l];
}
