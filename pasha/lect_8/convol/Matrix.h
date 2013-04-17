#pragma once

#include <complex>
#include <fftw3.h>

class Matrix {
	fftw_complex *pDat;
	int h, w;
	Matrix(const Matrix&); //копирующий конструктор
public:
	Matrix(int,int);
	~Matrix();
	int height() const;
	int width() const;
	std::complex<double>& at(int,int);
	const std::complex<double>& at(int,int) const;
	void load_matrix(const char*);
	void save_matrix(const char*);
	void mult(const Matrix&, const Matrix&);
	Matrix& operator= (const Matrix&);
};
