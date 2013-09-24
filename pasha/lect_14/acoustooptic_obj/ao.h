#pragma once

#include <iostream>
#include <complex>

class AO {
	std::complex<double> c0, c1;
public:
	AO() : c0(1), c1(0) {}
	AO(std::complex<double> c00, std::complex<double> c11) : c0(c00), c1(c11) {}
	friend std::ostream& operator<<(std::ostream&, const AO&);
	AO operator*(std::complex<double>) const;
	AO operator+(const AO& r) const; 
	AO deriv(double, double, double) const;
};