#include <iostream>
#include <fftw3.h>

using namespace std;

int main() {
	int h=100, w=100;
	fftw_complex *psource=(fftw_complex *)fftw_malloc(h*w*sizeof(fftw_complex));
	fftw_complex *pdestination=(fftw_complex *)fftw_malloc(h*w*sizeof(fftw_complex));
	
	int p=10, q=11;
	(complex<double>&) psource[p*w+q] = complex<double>(5.2,1.3);
	
	fftw_plan pln = fftw_plan_dft_2d(h,w,psource,pdestination, FFTW_FORWARD, FFTW_ESTIMATE);
	
	fftw_execute(pln); //исполнить план
	
	fftw_destroy_plan(pln);
	fftw_free(psource);
	fftw_free(pdestination);
}