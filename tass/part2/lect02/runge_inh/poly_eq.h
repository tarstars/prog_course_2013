#pragma once

#include <iostream>
#include <complex>

class PolyEq {
  std::complex<double> val;
 public:
 PolyEq() : val(1) {}
 PolyEq(std::complex<double> xval) : val(xval) {}
  friend std::ostream& operator<<(std::ostream&, const PolyEq&);
  PolyEq operator*(std::complex<double>) const;
  PolyEq operator+(const PolyEq& r) const;
  PolyEq deriv(double) const;
};
