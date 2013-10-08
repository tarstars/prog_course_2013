#include "Tensor4.h"

using namespace std;

Tensor4::Tensor4() : v(81) {
    for(int i=0; i<81; ++i) {
        v[i] = 0;
    }
}

void
Tensor4::set(int i, int j, int k, int l, double val) {
    checkRE(i, j, k, l);
    v[j + 3*i + 9*k + 27*l] = val;
}

double
Tensor4::at(int i, int j, int k, int l) const {
    checkRE(i, j, k, l);
    return v[j + 3*i + 9*k + 27*l];
}

ostream& operator <<(ostream& os, const Tensor4& t) {
    os << scientific;
    os.precision(2);
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            for(int k = 0; k < 3; k++) {
                for(int l = 0; l < 3; l++) {
                    os << t.at(i, j, k, l) << ";  ";
                }
                os << endl;
            }
        }
        os << endl << endl;
    }
    return os;
}
