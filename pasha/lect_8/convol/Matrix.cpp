#include "Matrix.h"

using namespace std;

Matrix::Matrix(int hh, int ww): h(hh), w(ww) {
	pDat=(fftw_complex*) fftw_malloc(h*w*sizeof(fftw_complex));
}

Matrix::~Matrix() {
	fftw_free(pDat);
}

Matrix::Matrix(const Matrix& r) {
	h=r.h;
	w=r.w;
	pDat=(fftw_complex*) fftw_malloc(h*w*sizeof(fftw_complex));
	for(int i=0; i<h*w; ++i) {
		pDat[i]=r.pDat[i];
	}
}

Matrix::Matrix& operator= (const Matrix& r) {
	if(this==&r) {return *this;}
	h=r.h;
	w=r.w;
	delete []pDat;
	pDat=(fftw_complex*) fftw_malloc(h*w*sizeof(fftw_complex));
	for(int i=0; i<h*w; ++i) {
		pDat[i]=r.pDat[i];
	}
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

Matrix
Matrix::load_matrix(const char* fn) { //fn = file name
	QImage image(fn);
	//int w = image.width();
	//int h = image.height();
	//delete []pDat;
	//pDat=(fftw_complex*) fftw_malloc(h*w*sizeof(fftw_complex));
	for(int p=0; p<hh; ++p) {
		for(int q=0; q<ww; ++q) {
			QRgb color = image.pixel(p,q);
			pDat[p*w+q] = (255-qRed(color))/255;
		}
	}
	return *this;
}

void
Matrix::save_matrix(const Matrix& m, const char* fn) {
	QImage image(h, w, QImage::Format_ARGB32_Premultiplied);
	for(int p=0 ; p<h; p++) {
		for(int q=0; q<w; q++) {
			double ampl = abs(m.at(p,q));
			int color = int(255-255*ampl);
			image.setPixel( p, q, qRgb(color, 0, 0) );
		}
	}
	image.save(fn);
}

Matrix
Matrix::mult(const Matrix& m1, const Matrix& m2) {
	hm=m1.h;
	wm=m1.w;
	Matrix m(hm, wm);
	for(int p=0; p<hm; ++p) {
		for(int q=0; q<wm; ++q) {
			m.pDat[p*wm+q] = m1.pDat[p*wm+q] * m2.pDat[p*wm+q];
		}
	}
	return m;
}