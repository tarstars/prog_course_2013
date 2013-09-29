#include <QImage>

#include "Matrix.h"

using namespace std;

Matrix::Matrix(int hh, int ww): h(hh), w(ww) {
	pDat=(fftw_complex*) fftw_malloc(h*w*sizeof(fftw_complex));
}

Matrix::~Matrix() {
	fftw_free(pDat);
}

/*Matrix::Matrix(const Matrix& r) {
	h=r.h;
	w=r.w;
	pDat=(fftw_complex*) fftw_malloc(h*w*sizeof(fftw_complex));
	for(int i=0; i<h*w; ++i) {
		pDat[i]=r.pDat[i];
	}
}*/

Matrix&
Matrix::operator= (const Matrix& r) {
	if(this==&r) {return *this;}
	h=r.h;
	w=r.w;
	delete []pDat;
	pDat=(fftw_complex*) fftw_malloc(h*w*sizeof(fftw_complex));
	for(int i=0; i<h*w; ++i) {
	  pDat[i][0]=r.pDat[i][0];
	  pDat[i][1]=r.pDat[i][1];
	}
	return *this;
}

int Matrix::height() const { return h;}

int Matrix::width() const { return w;}

complex<double>&
Matrix::at(int p, int q) {
	return (complex<double>&)pDat[p*w+q];
}

const complex<double>&
Matrix::at(int p, int q) const {
	return (complex<double>&)pDat[p*w+q];
}

void
Matrix::load_matrix(const char* fn) { //fn = file name
	QImage image(fn);
	int wi = image.width();
	int hi = image.height();
	delete []pDat;
	pDat=(fftw_complex*) fftw_malloc(h*w*sizeof(fftw_complex));
	for(int p=0; p<hi; ++p) {
		for(int q=0; q<wi; ++q) {
			QRgb color = image.pixel(p,q);
			fftw_complex val;
			val[0] = (255-qRed(color))/255;
			pDat[p*wi+q][0] = val[0];
		}
	}
}

void
Matrix::save_matrix(const char* fn) {
	QImage image(h, w, QImage::Format_ARGB32_Premultiplied);
	/*double max=0;
	for(int p=0 ; p<h; p++) {
		for(int q=0; q<w; q++) {
			if(max < abs(at(p,q))) {
				max = abs(at(p,q));
			}
		}
	}*/
	for(int p=0 ; p<h; p++) {
		for(int q=0; q<w; q++) {
			double ampl = abs(at(p,q)); // /max
			int color = int(255-255*ampl);
			image.setPixel( p, q, qRgb(color, 0, 0) );
		}
	}
	image.save(fn);
}

void
Matrix::mult(const Matrix& m1, const Matrix& m2) {
	int h = m1.h;
	int w = m1.w;
	delete []pDat;
	pDat=(fftw_complex*) fftw_malloc(h*w*sizeof(fftw_complex));
	for(int p=0; p<h; ++p) {
		for(int q=0; q<w; ++q) {
			pDat[p*w+q][0] = m1.pDat[p*w+q][0] * m2.pDat[p*w+q][0] -
							m1.pDat[p*w+q][1] * m2.pDat[p*w+q][1];
			pDat[p*w+q][1] = m1.pDat[p*w+q][0] * m2.pDat[p*w+q][1] +
							m1.pDat[p*w+q][1] * m2.pDat[p*w+q][0];
		}
	}
}
