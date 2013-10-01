#include "Mat3.h"

Mat3::
~Mat3() {
    delete []matrix;
}

Mat3::Mat3(): matrix(new double[9]()) {}

double*
Mat3::set(int i, int j) {
    return matrix + j + 3*i;
}

double
Mat3::at(int i, int j) const{
    return matrix[j + 3*i];
}
