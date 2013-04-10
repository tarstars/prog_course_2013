#include "Matrix.h"

using namespace std;

Matrix::Matrix(int hh, int ww): h(hh), w(ww) {
	pDat=(fftw_complex*) fftw_malloc(h*w*sizeof(fftw_complex));
}

Matrix::~Matrix() {
	fftw_free(pDat);
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