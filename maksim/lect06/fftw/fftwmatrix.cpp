#include "fftwmatrix.h"
#include <string.h>
using namespace std;

FFTWMatrix::FFTWMatrix(int hh, int ww) : h(hh), w(ww) {
  pDat = (fftw_complex*) fftw_malloc(h * w * sizeof(fftw_complex));
}

FFTWMatrix::FFTWMatrix(const FFTWMatrix& fm) {
  h = fm.h;
  w = fm.w;
  pDat = (fftw_complex *)fftw_malloc( w*h*sizeof(fftw_complex) );
  memcpy( (void*)pDat, (void*)fm.pDat , w*h*sizeof(fftw_complex) ); 
}

FFTWMatrix& FFTWMatrix::operator=(const FFTWMatrix& fm) {
  if( pDat != 0 ) fftw_free(pDat);
  if( pDat == fm.pDat ) return *this;
  h = fm.h;
  w = fm.w;
  pDat = (fftw_complex *)fftw_malloc( w*h*sizeof(fftw_complex) );
  memcpy( (void*)pDat, (void*)fm.pDat , w*h*sizeof(fftw_complex) ); 
  return *this;
}

FFTWMatrix::~FFTWMatrix() {
  fftw_free(pDat);
}

int
FFTWMatrix::height() const {
  return h;
}

int
FFTWMatrix::width() const {
  return w; 
}

complex<double>& 
FFTWMatrix::at(int p, int q) {
  return (complex<double>&)pDat[p * w + q];
}

const std::complex<double>& 
FFTWMatrix::at(int p, int q) const {
  return (complex<double>&)pDat[p * w + q];
}

void FFTWMatrix::take_from(const FFTWMatrix& fm) {
  if( pDat != 0 ) fftw_free(pDat);
  if( pDat == fm.pDat ) return;
  h = fm.h;
  w = fm.w;
  pDat = (fftw_complex *)fftw_malloc( w*h*sizeof(fftw_complex) );
  memcpy( (void*)pDat, (void*)fm.pDat , w*h*sizeof(fftw_complex) );   
}
