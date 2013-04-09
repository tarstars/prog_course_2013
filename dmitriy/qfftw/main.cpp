#include <iostream>
#include <complex>

#include "fftwmatrix.h"
#include "fftwplan.h"

int main(int argc, char** argv)
{
    /*int h=100;
    int w=100;
    fftw_complex *psource = (fftw_complex*)fftw_malloc(h*w*sizeof(fftw_complex));
    fftw_complex *pdest = (fftw_complex*)fftw_malloc(h*w*sizeof(fftw_complex));

    int p=10, q=11;
    (std::complex<double>&)psource[p*w+q] = std::complex<double>(5,10);

    fftw_plan plan = fftw_plan_dft_2d(h,w,psource,pdest,FFTW_FORWARD,FFTW_ESTIMATE);

    fftw_execute(plan);
    fftw_destroy_plan(plan);

    fftw_free(psource);
    fftw_free(pdest);*/

    if(argc<3)
    {
        qDebug()<<"Please provide at least input image1, input image2";
        return 1;
    }

    QImage img_first(QString::fromLocal8Bit(argv[1]));
    if(img_first.isNull())
    {
        qDebug()<<"Cannot load first image";
        return 2;
    }

    QImage img_second(QString::fromLocal8Bit(argv[2]));
    if(img_second.isNull())
    {
        qDebug()<<"Cannot load second image";
        return 2;
    }

    if(img_first.size() != img_second.size())
    {
        qDebug()<<"Imgaes must have equal size!!!";
        return 3;
    }

    FFTWMatrix orig_matrix(img_first);
    FFTWMatrix fftw_matrix(img_first.width(),img_first.height());

    FFTWPlan fwd_plan(&orig_matrix,&fftw_matrix, FFTW_FORWARD);

    if(!fwd_plan.isValid())
    {
        qDebug()<<"Forward plan is invalid";
        return 3;
    }

    if(!fwd_plan.execute())
    {
        qDebug()<<"Forward plan execution for first image failed";
        return 4;
    }

    FFTWMatrix fft_first(fftw_matrix);
    {
        QImage fft1_debug=fft_first.toImage();
        if(!fft1_debug.isNull())
        {
            fft1_debug.save("fft1.png");
        }
    }

    ////////////////////////
    if(!orig_matrix.fromImage(img_second))
    {
        //should never happen
        qDebug()<<"Cannot load second image into matrix";
        return 2;
    }

    if(!fwd_plan.execute())
    {
        qDebug()<<"Forward plan execution for second image failed";
        return 4;
    }

    {
        fftw_matrix.setFormat(orig_matrix.getFomat());
        QImage fft2_debug=fftw_matrix.toImage();
        if(!fft2_debug.isNull())
        {
            fft2_debug.save("fft2.png");
        }
    }


    //now we have first fft in fft_first, secondf fft in fftw_matrix
    if(!fft_first.mutliplyBy(fftw_matrix))
    {
        qDebug()<<"Matrix multiplication failed";
        return 5;
    }

    //fftw_matrix is now free;
    fftw_matrix.zeros();
    FFTWPlan rev_plan(&fft_first,&fftw_matrix, FFTW_BACKWARD);
    if(!rev_plan.isValid())
    {
        qDebug()<<"Cannot create rev plan";
        return 3;
    }

    if(!rev_plan.execute())
    {
        qDebug()<<"Reverse plan execution failed";
        return 4;
    }

    fftw_matrix.setFormat(orig_matrix.getFomat());
    QImage output = fftw_matrix.toImage();
    if(output.isNull())
    {
        qDebug()<<"Cannot convert ouput matrix to image";
        return 6;
    }

    if(argc>3)
    {
        output.save(QString::fromLocal8Bit(argv[3]));
    }
    else
    {
        output.save("output.png");
    }
    ///////////////////

    /*
    FFTWMatrix first_rev(orig_matrix.width(),orig_matrix.height());
    FFTWPlan rev_plan(&fftw_matrix,&first_rev, FFTW_BACKWARD);
    if(!rev_plan.isValid())
    {
        qDebug()<<"Reverse plan is onvalid";
        return 10;
    }

    rev_plan.execute();
    QImage output = first_rev.toImage();
    if(!output.isNull())
    {
        output.save("output.png");
    }
    */

    return 0;
}

//TODO
// 2 classes: fftw_matrix (containing psource or pdest), fftw_plan (manager)
// constructor: malloc; destructor:free
