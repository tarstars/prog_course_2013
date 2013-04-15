#include "fftwplan.h"

#include "fftwplan.h"

FFTWPlan::FFTWPlan(FFTWMatrix& fx, FFTWMatrix& fk, FFTW_DIR fftw_dir) {
  int h = fx.height(), w = fx.width();
  fftw_complex *pSource = reinterpret_cast<fftw_complex *>(&fx.at(0, 0));
  fftw_complex *pDestination = reinterpret_cast<fftw_complex*>(&fk.at(0,0));
  switch(fftw_dir) { 
  case FORWARD : pln = fftw_plan_dft_2d (h, w, pSource, pDestination, FFTW_FORWARD, FFTW_ESTIMATE); break;
  case BACKWARD : pln = fftw_plan_dft_2d (h, w, pSource, pDestination, FFTW_BACKWARD, FFTW_ESTIMATE); 
  }
}

void FFTWPlan::execute() {
  fftw_execute(pln);
}

FFTWPlan::~FFTWPlan() {
  fftw_destroy_plan(pln);
}
