#ifndef FFTWPLAN_H
#define FFTWPLAN_H

#include <fftw3.h>

#include "defs.h"

class FFTWMatrix;

class FFTWPlan
{
    public:
        //not an ownre -> so no creation, no destruction!!!
        FFTWPlan(FFTWMatrix *source, FFTWMatrix *dest, int direction);
        ~FFTWPlan()
        {
            if(is_valid)
            {
                fftw_destroy_plan(m_plan);
                m_plan=0;
            }
        }

        inline bool isValid() const
        {
            return is_valid;
        }

        bool execute();

    private:
        DISALLOW_COPY_AND_ASSIGN(FFTWPlan);
        fftw_plan m_plan;
        bool is_valid;

        FFTWMatrix* m_src;
        FFTWMatrix* m_dst;
};

#endif // FFTWPLAN_H
