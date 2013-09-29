#pragma once

#include <complex>
#include <fftw3.h>

class FFTWMatrix {
  fftw_complex *pDat;
  int h, w; 
 public:
  FFTWMatrix(const FFTWMatrix&);
  FFTWMatrix& operator=(const FFTWMatrix&);
  FFTWMatrix(int, int);
  ~FFTWMatrix();
  int height() const;
  int width() const;
  std::complex<double>& at(int, int);
  const std::complex<double>& at(int, int) const;
  void take_from(const FFTWMatrix&);
};
