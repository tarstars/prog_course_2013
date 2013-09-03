#include <complex>

#include <QtTest/QtTest>

#include "matrix.h"

using namespace std;

class TestMatrix : public QObject {
  Q_OBJECT

  private slots:

  void test_width();
  void test_content();
};

namespace QTest {
  template<>
  char* toString(const complex<double>& r) {
    QByteArray ba = "(" + QByteArray::number(real(r)) + 
      ", " + QByteArray::number(imag(r)) + ")";
    return qstrdup(ba.data());
  }
}

void
TestMatrix::test_width() {
  Matrix dat(15, 17);
  QCOMPARE(dat.width(), 17);
  QCOMPARE(dat.height(), 15);
}

void
TestMatrix::test_content() {
  Matrix dat(15, 17);

  complex<double> val1(3.14, 2.71);
  complex<double> val2(2.03, 1.60);

  dat.at(12, 16) = val1;
  dat.at(13, 16) = val2;

  QCOMPARE(dat.at(12,16), val1);
  QCOMPARE(dat.at(13,16), val2);
}

QTEST_MAIN(TestMatrix)
#include "test.moc"
