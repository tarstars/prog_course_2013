#include <QtTest/QtTest>
#include "matrix.h"

class TestMatrix: public QObject
{
  Q_OBJECT
  private slots:
  void setGet();
  void testTrace();
};

void TestMatrix::setGet()
{
  Matrix dat(3,3);
  
  dat.Set(0, 0, 5);
  dat.Set(1, 0, 15);
  dat.Set(2, 2, 25);

  QVERIFY(dat.Get(0, 0) == 5);
  QVERIFY(dat.Get(1, 0) == 15);
  QVERIFY(dat.Get(2, 2) == 25);
}

void TestMatrix::testTrace() {
  Matrix dat(3,3);
  
  dat.Set(0, 0, 5);
  dat.Set(0, 1, 15);
  dat.Set(0, 2, 25);

  dat.Set(1, 0, 35);
  dat.Set(1, 1, 35);
  dat.Set(1, 2, 35);

  dat.Set(2, 0, 45);
  dat.Set(2, 1, 45);
  dat.Set(2, 2, 45);

  QVERIFY(dat.trace() == 85);

}

 QTEST_MAIN(TestMatrix)
 #include "testmatrix.moc"
