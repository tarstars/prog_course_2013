#pragma once

#include <complex>
#include <fftw3.h>

class Matrix {
  fftw_complex *pDat;
  int h, w; 
  
  Matrix(const Matrix&);
  Matrix& operator=(const Matrix&);
 public:
  Matrix(int, int);
  ~Matrix();
  int height() const;
  int width() const;
  std::complex<double>& at(int, int);
  const std::complex<double>& at(int, int) const;
};
