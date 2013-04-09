#include "../fftwmatrix.h"

void test_dimensions(int w, int h)
{
    FFTWMatrix matrix(5,7);
    if(matrix.width()!=5)
    {
        qDebug()<<"Width OK";
    }
    else
    {
        qDebug()<<"Width FAIL: expected "<<5<<", got "<<matrix.width();
    }
}

int main(void)
{
    test_dimensions(5,7);
    test_dimensions(6,8);
}
