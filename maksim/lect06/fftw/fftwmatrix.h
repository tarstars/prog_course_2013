#ifndef _FFTWMATRIX_
#define _FFTWMATRIX_

#include <fftw3.h>
#include <complex>

class FFTWMatrix {
  int w, h; 
  fftw_complex *pA;
public:
  FFTWMatrix() {};
  FFTWMatrix(int, int);
  FFTWMatrix(const FFTWMatrix&); 
  ~FFTWMatrix(); // Destructor
  std::complex<double> at(int, int); 
  int width();
  int height();
  void take_from(const FFTWMatrix&); 
  friend FFTWMatrix load_matrix(const char*);
  friend void save_to_file(FFTWMatrix&, const char*);
  friend class FFTWPlan;
  friend FFTWMatrix mult(FFTWMatrix&, FFTWMatrix&);
};

#endif
