#pragma once

#include <complex>
#include <fftw3.h>

class Matrix {
	fftw_complex *pDat;
	int h, w;
	Matrix(const Matrix&); //копирующий конструктор
	Matrix& operator= (const Matrix&);
public:
	Matrix(int,int);
	~Matrix();
	int height() const;
	int width() const;
	std::complex<double>& at(int,int);
	const std::complex<double>& at(int,int) const;
	friend Matrix load_matrix(const char*);
	friend void save_matrix(const Matrix&, const char*);
	friend Matrix mult(const Matrix&, const Matrix&);
};