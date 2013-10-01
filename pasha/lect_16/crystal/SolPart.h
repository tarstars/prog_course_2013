#pragma once

class SolPart {
    double* sol;
public:
    SolPart();
    double at(int) const;
    double* set(int);
    ~SolPart();
};
