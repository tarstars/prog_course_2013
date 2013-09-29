#include "fftwmatrix.h"
#include <QImage>

using namespace std;

FFTWMatrix load_matrix(const char* filename) {
  QImage img(filename); // read image from file
  int h = img.height();
  int w = img.width();
  FFTWMatrix fm(h, w); // create fftwmatrix
  for(int p = 0 ; p < h; p++) // fill the matrix
    for(int q = 0; q < w; q++) {
      QRgb tsvet = img.pixel(p,q);
      fm.at(p,q) = complex<double>(qRed(tsvet),0);
      // fm.at(p,q) = complex<double>(img.pixel(p,q),0);
    }
  return fm;  // return the matrix
} 

FFTWMatrix mult(FFTWMatrix& m1, FFTWMatrix& m2) {
  int h = m1.height(), w = m1.width();
  FFTWMatrix ans(h, w);
  for(int p = 0; p < h; p++)
    for(int q = 0; q < w; q++) {
      ans.at(p,q) = m1.at(p,q)*m2.at(p,q);
    }
  return ans; 
}

void save_to_file(FFTWMatrix& fm, const char* filename) {
  int h = fm.height(); int w = fm.width();
  QImage pict( h, w, QImage::Format_ARGB32_Premultiplied);
  for(int p = 0 ; p < h; p++)
    for(int q = 0; q < w; q++) {
      double val = fm.at(p,q).real();
            int v = int(val);
            pict.setPixel( p, q, qRgb(v, v, v) );
      //      unsigned int v = (unsigned int)val;
      //    QRgb tsvet = v;
      //    pict.setPixel( p, q, tsvet);
    }
  pict.save(filename);
}

void normalize(FFTWMatrix& cc) {
  complex<double> max = cc.at(0,0);
  int h = cc.height(); 
  int w = cc.width();
  for(int i=0; i<h; i++)
    for(int j=0; j<w; j++) 
      if( cc.at(i,j).real() > max.real()) max = cc.at(i,j);

  for(int i=0; i<h; i++)
    for(int j=0; j<w; j++) 
      cc.at(i,j) = complex<double>( 255*cc.at(i,j).real()/max.real(), 0);
}

