#pragma once

class Tensor4 {
    double* tens;
public:
    Tensor4();
    double* set(int, int, int, int);
    double at(int, int, int, int) const;
    ~Tensor4();
};
