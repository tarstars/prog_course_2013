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

int
Matrix::height() const {
	return h;
}

int
Matrix::width() const {
	return w;
}

complex<double>&
Matrix::at(int p, int q) {
	return (complex<double>&)pDat[p*w+q];
}

const complex<double>&
Matrix::at(int p, int q) const {
	return (complex<double>&)pDat[p*w+q];
}

