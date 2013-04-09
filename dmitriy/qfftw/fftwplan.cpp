#include "fftwplan.h"

#include "fftwmatrix.h"

FFTWPlan::FFTWPlan(FFTWMatrix *source, FFTWMatrix *dest, int direction) :
    m_plan(0), is_valid(false), m_src(source), m_dst(dest)
{
    if(source && dest)
    {
        if(source->size()==dest->size())
        {
            m_plan = fftw_plan_dft_2d(source->height(),source->width(),
                                      const_cast<fftw_complex*>(source->getData()),
                                      const_cast<fftw_complex*>(dest->getData()),
                                      direction,FFTW_ESTIMATE);
            dest->setFormat(source->getFomat());
            is_valid = true;
        }
        else
        {
            qDebug()<<"Incompatible source and dest - cannot create plan";
        }
    }
    else
    {
        qDebug()<<"NULL source or plan";
    }
}

bool FFTWPlan::execute()
{
    if(is_valid && m_src && m_dst)
    {
        fftw_execute(m_plan);
        m_dst->normalize();
        return true;
    }

    qDebug()<<"Invalid plan or src or dst";
    return false;
}
