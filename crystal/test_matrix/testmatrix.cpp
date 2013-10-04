#include <QtTest/QtTest>
#include "matrix.h"

class TestMatrix: public QObject
{
  Q_OBJECT
  private slots:
  void setGet();
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

 QTEST_MAIN(TestMatrix)
 #include "testmatrix.moc"
