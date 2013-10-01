#pragma once

class Mat3 {
    double* matrix;
public:
    Mat3();
    double* set(int, int);
    double at(int, int) const;
    ~Mat3();
};
