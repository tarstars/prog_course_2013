#ifndef FFTWMATRIX_H
#define FFTWMATRIX_H

#include <fftw3.h>

#include <QImage>
#include <QSize>

#include <complex>

#include "defs.h"

typedef std::complex<double> ComplexDouble;

class FFTWMatrix
{
    public:
        FFTWMatrix() : data(0), m_width(0), m_height(0){}
        FFTWMatrix(int width, int height);
        FFTWMatrix(const QImage& image);

        FFTWMatrix(const FFTWMatrix& other);

        ~FFTWMatrix();

        bool isValid() const { return (data!=0);}
        int width() const { return m_width;}
        int height() const { return m_height;}
        QSize size() const { return QSize(m_width,m_height);}

        bool fromImage(const QImage& image);
        QImage toImage() const;

        inline ComplexDouble& at(unsigned x, unsigned y)
        {
            return data[y*m_width+x];
        }
        inline const ComplexDouble& at(unsigned x, unsigned y) const
        {
            return data[y*m_width+x];
        }

        inline const fftw_complex* getData() const
        {
            return reinterpret_cast<const fftw_complex*>(data);
        }

        inline bool mutliplyBy(const FFTWMatrix& other)
        {
            if(!isValid() || !other.isValid() || (this->size() != other.size()))
            {
                qDebug()<<"Cannot multiply - invalid matrices or size mismatch";
                return false;
            }

            int i=0,j=0;
            for(j = 0 ; j < m_height; ++j)
            {
                for(i = 0; i<m_width;++i)
                {
                    data[j*m_width+i] *= other.at(i,j);
                }
            }
            return true;
        }

        inline void normalize()
        {
            if(isValid())
            {
                double norm = m_width*m_height;
                int i=0,j=0;
                for(j = 0 ; j < m_height; ++j)
                {
                    for(i = 0; i<m_width;++i)
                    {
                        data[j*m_width+i] /= norm;
                    }
                }
            }
        }

        inline void zeros()
        {
            if(isValid())
            {
                memset(data,0,m_height*m_width*sizeof(data[0]));
            }
        }

        inline QImage::Format getFomat() const { return img_format;}
        inline void setFormat(QImage::Format fmt) { img_format = fmt;}

    private:
        ComplexDouble* data;
        int m_width;
        int m_height;
        QImage::Format img_format;

        //DISALLOW_COPY_AND_ASSIGN(FFTWMatrix);
        void operator=(const FFTWMatrix&);

        inline void clear()
        {
            if(data)
            {
                delete[] data;
                data=0;
            }
            m_width=0;
            m_height=0;
        }

        //no check for free!!!
        inline void make()
        {
            data = new ComplexDouble[m_width*m_height];
        }
};

#endif // FFTWMATRIX_H
