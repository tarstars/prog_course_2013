#include "fftwmatrix.h"
#include <string.h>
#include <QImage>

using namespace std;

FFTWMatrix::FFTWMatrix(int _w, int _h): w(_w), h(_h) {
  pA = (fftw_complex *)fftw_malloc( w*h*sizeof(fftw_complex) );
}

FFTWMatrix::FFTWMatrix(const FFTWMatrix& fm) {
  h = fm.h;
  w = fm.w;
  pA = (fftw_complex *)fftw_malloc( w*h*sizeof(fftw_complex) );
  memcpy( (void*)pA, (void*)fm.pA , w*h*sizeof(fftw_complex) ); 
}

FFTWMatrix::~FFTWMatrix() {
  fftw_free(pA);
}

complex<double> FFTWMatrix::at(int p, int q) {
  return (complex<double>&)pA[ p*w + q ];
}

int FFTWMatrix::width() {
  return w;
}

int FFTWMatrix::height() {
  return h;
}

void FFTWMatrix::take_from(const FFTWMatrix& fm) {
  if( pA != 0 ) fftw_free(pA);
  if( pA == fm.pA ) return;
  h = fm.h;
  w = fm.w;
  pA = (fftw_complex *)fftw_malloc( w*h*sizeof(fftw_complex) );
  memcpy( (void*)pA, (void*)fm.pA , w*h*sizeof(fftw_complex) ); 
}

FFTWMatrix load_matrix(const char* filename) {
  QImage img(filename); // read image from file
  int h = img.height();
  int w = img.width();
  FFTWMatrix fm(h, w); // create fftwmatrix
  for(int p = 0 ; p < h; p++) // fill the matrix
    for(int q = 0; q < w; q++) {
      QRgb tsvet = img.pixel(p,q);
      fm.pA[ p*w + q ][0] = (-1)*(qRed(tsvet)-255.0)/255.0;
      fm.pA[ p*w + q ][1] = 0;
    }
  return fm;  // return the matrix
}

void save_to_file(FFTWMatrix& fm, const char* filename) {
  // Here we want to save a matrix as image
  // Step 1: Create image for saving
  // Step 2: Write the matrix into image
  // Step 3: Save image as filename.bmp
  QImage pict( fm.h, fm.w, QImage::Format_ARGB32_Premultiplied); // Step 1
  for(int p = 0 ; p < fm.h; p++) // Step 2
    for(int q = 0; q < fm.w; q++) {
      double val = fm.at(p,q).real();
      int v = int(255-255*val);
      pict.setPixel( p, q, qRgb(v, v, v) );
    }
  pict.save(filename); // Step 3  
}
