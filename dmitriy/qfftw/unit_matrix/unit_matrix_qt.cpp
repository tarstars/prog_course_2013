#include <QtTest/QtTest>

/*
* in pro : CONFIG += qtestlib
* include: DEPENDPATH/INCLUDEPATH += ..
*/

class TestMatrix : public QObject
{
    Q_OBJECT

    private slots:
        void test_width();
}

void TestMatrix::test_width()
{
    Matrix dat(15,17);
    QCOMPARE(dat.width(),15);
    QCOMPARE(dat.height(),17);    
}

QTEST_MAIN(TestMatrix)
#include "unix_matrix_qt.moc"


/*Add type to QtTest

namespace QtTest
{
    template<>
    char* toString(const std::complex<double>& r)
    {
        QByteArrasy ba = "(" + QByteArray::number(r.real()) + "," + QByteArray:number(r.imag())+")";
        return qstrdup(ba.data());
    }
}

*/
