#include <iostream>
#include <fftw3.h>
#include <complex>

using namespace std;

int main() {
	
	int H=100; W=100;
	
	QImage a(H, W, QImage::Format_ARGB32_Premultiplied);
	for(int p=0 ; p<H; p++) {
		for(int q=0; q<W; q++) {
			double ampl = sin(10*p/H) * sin(20*q/W);
			if(ampl>0.8) {
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
	
	Matrix a(hi,wi), a_F(hi,wi), b_F(hi,wi), c(hi,wi);
	
	fftw_complex *pa = (fftw_complex *)fftw_malloc(hi*wi*sizeof(fftw_complex));
	fftw_complex *pa_F = (fftw_complex *)fftw_malloc(hi*wi*sizeof(fftw_complex));
	
	fftw_plan pln = fftw_plan_dft_2d(hi, wi, pa, pa_F, FFTW_FORWARD, FFTW_ESTIMATE);
	//____________________________________________________
	
	a.load_matrix("b.png");
	for(int p=0 ; p<hi; p++) {
		for(int q=0; q<wi; q++) {
			(complex<double>&) pa[p*w+q] = a.at(p,q);
		}
	}
	fftw_execute(pln);
	for(int p=0 ; p<hi; p++) {
		for(int q=0; q<wi; q++) {
			a_F.at(p,q) = (complex<double>&) pa_F[p*w+q];
		}
	}
	save_matrix(a_F, "bF.png");
	b_F = a_F; //т.к. aF будет будет перезаписано планом
	//____________________________________________________
	
	a.load_matrix("a.png");
	for(int p=0 ; p<hi; p++) {
		for(int q=0; q<wi; q++) {
			(complex<double>&) pa[p*w+q] = a.at(p,q);
		}
	}
	fftw_execute(pln);
	for(int p=0 ; p<hi; p++) {
		for(int q=0; q<wi; q++) {
			a_F.at(p,q) = (complex<double>&) pa_F[p*w+q];
		}
	}
	save_matrix(a_F, "aF.png");
	//____________________________________________________
	
	c.mult(a_F, b_F);
	save_matrix(c, "c.png");
	
	fftw_destroy_plan(pln);
	fftw_free(pa);
	fftw_free(pa_F);
	
	return 1;
}