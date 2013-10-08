#pragma once

#include <iostream>

class Vec3{
	double dat[3];
public:
	Vec3();
	Vec3(double m, double n, double k);

	//Vec3 operator+ (const Vec3& t);
	//int operator* (Vec3 p, Vec3 q);
	
	void set(int, double);
	double at(int) const;
	double abs() const;
	Vec3 normalized() const;
	void normalize();

	friend std::ostream& operator << (std::ostream&, const Vec3&);
};

