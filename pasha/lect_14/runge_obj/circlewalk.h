#pragma once

#include <iostream>

class circlewalk {
	double x, y;
public:
	circlewalk() : x(1), y(0) {}
	circlewalk(double xx, double yy) : x(xx), y(yy) {}
	friend std::ostream& operator<<(std::ostream&, const circlewalk&);
	circlewalk operator*(double) const; // не будет изменять объект, к которому применяется
	circlewalk operator+(const circlewalk& r) const; 
	circlewalk deriv(double) const;
};