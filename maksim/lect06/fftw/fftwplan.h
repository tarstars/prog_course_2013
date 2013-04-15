#pragma once

#include "fftwmatrix.h"

enum FFTW_DIR { FORWARD, BACKWARD };

class FFTWPlan {
  fftw_plan pln;
public:
  FFTWPlan(FFTWMatrix&, FFTWMatrix&, FFTW_DIR);
  ~FFTWPlan();
  void execute();
};
