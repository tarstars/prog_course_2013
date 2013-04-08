#ifndef _FFTWPLAN_
#define _FFTWPLAN_

#include "fftwmatrix.h"

enum FFTW_DIR { FORWARD, BACKWARD };

class FFTWPlan {
  // 1. Constructor on two matrixes
  // 2. Execute
  fftw_plan pln;
public:
  FFTWPlan(FFTWMatrix&, FFTWMatrix&, FFTW_DIR);
  ~FFTWPlan();
  void execute();
};

#endif
