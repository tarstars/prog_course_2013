#include <iostream>
#include <fftw3.h>
#include <complex>
#include <QImage>

#include "Matrix.h"

using namespace std;

#undef main //без этого не компилировалось!!!

int main() {
	
	int H=1000, W=1000;
	
	QImage a(H, W, QImage::Format_ARGB32_Premultiplied);
	
	for(int p=0 ; p<H; p++) {
		for(int q=0; q<W; q++) {
			double ampl = sin(10*p/H) * sin(20*q/W);
			if(ampl>0.95) {
				a.setPixel( p, q, qRgb(255,0,0) );
			}
			else {
				a.setPixel( p, q, qRgb(0,0,0) );
			}
		}
	}
	
	a.save("a.png");
	
	QImage b(H, W, QImage::Format_ARGB32_Premultiplied);
	
	for(int p=0 ; p<H; p++) {
		for(int q=0; q<W; q++) {
			if(q<W/5 && p<H/5) {
				b.setPixel( p, q, qRgb(255,0,0) );
			}
			else {
				b.setPixel( p, q, qRgb(0,0,0) );
			}
		}
	}
	
	b.save("b.png");
	//____________________________________________________
	
	QImage img("a.png");
	int wi = img.width();
	int hi = img.height();
	
	Matrix A(hi,wi), A_F(hi,wi), B_F(hi,wi), C(hi,wi);
	
	fftw_complex *pa = (fftw_complex *)fftw_malloc(hi*wi*sizeof(fftw_complex));
	fftw_complex *pa_F = (fftw_complex *)fftw_malloc(hi*wi*sizeof(fftw_complex));
	
	fftw_plan pln = fftw_plan_dft_2d(hi, wi, pa, pa_F, FFTW_FORWARD, FFTW_ESTIMATE);
	fftw_plan pln_back = fftw_plan_dft_2d(hi, wi, pa, pa_F, FFTW_BACKWARD, FFTW_ESTIMATE);
	//____________________________________________________
	
	A.load_matrix("b.png");
	for(int p=0 ; p<hi; p++) {
		for(int q=0; q<wi; q++) {
			(complex<double>&) pa[p*wi+q] = A.at(p,q);
		}
	}
	fftw_execute(pln);
	for(int p=0 ; p<hi; p++) {
		for(int q=0; q<wi; q++) {
			A_F.at(p,q) = (complex<double>&) pa_F[p*wi+q];
		}
	}
	A_F.save_matrix("bF.png");
	B_F = A_F; //чтобы можно было скопировать код без изменений
	//____________________________________________________
	
	A.load_matrix("a.png");
	
	for(int p=0 ; p<hi; p++) {
		for(int q=0; q<wi; q++) {
			(complex<double>&) pa[p*wi+q] = A.at(p,q);
		}
	}
	
	fftw_execute(pln);
	
	for(int p=0 ; p<hi; p++) {
		for(int q=0; q<wi; q++) {
			A_F.at(p,q) = (complex<double>&) pa_F[p*wi+q];
		}
	}
	
	A_F.save_matrix("aF.png");
	//____________________________________________________
	
	C.mult(A_F, B_F);
	
	for(int p=0 ; p<hi; p++) {
		for(int q=0; q<wi; q++) {
			(complex<double>&) pa[p*wi+q] = C.at(p,q);
		}
	}
	
	fftw_execute(pln_back);
	
	for(int p=0 ; p<hi; p++) {
		for(int q=0; q<wi; q++) {
			C.at(p,q)= (complex<double>&) pa_F[p*wi+q];
		}
	}
	
	C.save_matrix("convolution.png");
	//____________________________________________________
	
	fftw_destroy_plan(pln);
	fftw_destroy_plan(pln_back);
	fftw_free(pa);
	fftw_free(pa_F);
	
	return 1;
}
