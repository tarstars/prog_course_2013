#include <iostream>
#include <fftw3.h>
#include <complex>

using namespace std;

int main() {

	//fftw_complex *psource=(fftw_complex *)fftw_malloc(h*w*sizeof(fftw_complex));
	//fftw_free(psource);
	
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
	
	QImage img("a.png");
	int wi = img.width();
	int hi = img.height();
	
	Matrix a(hi,wi), aF(hi,wi), bF(hi,wi), c(hi,wi);
	fftw_plan pln = fftw_plan_dft_2d(&a, &aF, FFTW_FORWARD, FFTW_ESTIMATE);
	
	a.load_matrix("b.png");
	fftw_execute(pln);
	save_matrix(aF, "bF.png");
	bF=aF; //т.к. aF будет будет перезаписано планом
	
	a.load_matrix("a.png");
	fftw_execute(pln);
	save_matrix(aF, "aF.png");
	
	c.mult(aF,bF);
	save_matrix(c, "c.png");
	
	fftw_destroy_plan(pln);
	
	return 1;
}