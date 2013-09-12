#pragma once

#include <iostream>

class PolyEq {
	double val;
public:
	PolyEq() : val(0.2) {}
	PolyEq(double xval) : val(xval) {}
	friend std::ostream& operator<<(std::ostream&, const PolyEq&);
	PolyEq operator*(double) const; // не будет изменять объект, к которому применяется
	PolyEq operator+(const PolyEq& r) const; 
	PolyEq deriv(double) const;
};