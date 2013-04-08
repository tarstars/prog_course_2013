#include "fftwplan.h"

FFTWPlan::FFTWPlan(FFTWMatrix& fxy, FFTWMatrix& fk, FFTW_DIR fftw_dir) {
  switch(fftw_dir) { 
    case FORWARD : pln = fftw_plan_dft_2d (fxy.h, fxy.w, fxy.pA, fk.pA, FFTW_FORWARD, FFTW_ESTIMATE); break;
    case BACKWARD : pln = fftw_plan_dft_2d (fxy.h, fxy.w, fxy.pA, fk.pA, FFTW_BACKWARD, FFTW_ESTIMATE); 
  }
}

void FFTWPlan::execute() {
  fftw_execute(pln);
}

FFTWPlan::~FFTWPlan() {
  fftw_destroy_plan(pln);
}
