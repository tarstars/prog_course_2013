#pragma once

class Vec3 {
    double* vec3;
public:
    Vec3();
    double at(int) const;
    double* get(int);
    ~Vec3();
};
