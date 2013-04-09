#include "fftwmatrix.h"

FFTWMatrix::FFTWMatrix(int width, int height) : data(0), m_width(width), m_height(height),
    img_format(QImage::Format_Mono)
{
    if( (m_width>0) && (m_height>0))
    {
        make();
    }
}

FFTWMatrix::~FFTWMatrix()
{
    clear();
}

FFTWMatrix::FFTWMatrix(const QImage& image) :  data(0), m_width(0), m_height(0)
{
    (void)fromImage(image);
}

FFTWMatrix::FFTWMatrix(const FFTWMatrix& other) : data(0),
    m_width(other.width()),m_height(other.height()),
    img_format(other.img_format)
{
    if(other.isValid())
    {
        make();
        memcpy(data,other.getData(),m_width*m_height*sizeof(data[0]));
    }
}

bool FFTWMatrix::fromImage(const QImage &image)
{
    clear();
    if(image.isNull())
    {
        return false;
    }

    m_width = image.width();
    m_height = image.height();
    img_format = image.format();

    make();

    int i=0,j=0;
    for(j = 0 ; j < m_height; ++j)
    {
        for(i = 0; i<m_width;++i)
        {
            data[j*m_width+i] = (double)image.pixel(i,j);
        }
    }
    return true;
}

QImage FFTWMatrix::toImage() const
{
    if(!isValid())
    {
        return QImage();
    }

    QImage ret(size(),img_format);
    int i=0,j=0;
    for(j = 0 ; j < m_height; ++j)
    {
        for(i = 0; i<m_width;++i)
        {
            ret.setPixel(i,j,(uint)abs(data[j*m_width+i]));
            //ret.setPixel(i,j,(uint)(data[j*m_width+i].real()));
        }
    }
    return ret;
}
