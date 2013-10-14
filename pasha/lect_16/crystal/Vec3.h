#pragma once

#include <iostream>

class Vec3{
	double dat[3];
public:
	Vec3();
	Vec3(double m, double n, double k);
	void set(int, double);
	double at(int) const;
    friend std::ostream& operator<< (std::ostream&, const Vec3&);
    Vec3 normalized() const;
    void normalize();
    double abs() const;
    Vec3 operator* (const Vec3&) const;
};

