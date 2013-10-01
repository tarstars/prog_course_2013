#include <QtTest/QtTest>
#include "vec3.h"
#include "Tensor4.h"
#include "util.h"

class TestUtil: public QObject
{
  Q_OBJECT
  private slots:
  void testMakeTetragonalTensor();
};

void TestUtil::testMakeTetragonalTensor()
{
  //double c11, double c12, double c13, double c33, double c44, double c66
  Tensor4 tens = makeTetragonalTensor(11, 12, 13, 33, 44, 66);

  QVERIFY(tens.at(0,0,0,0) == 11);
  QVERIFY(tens.at(0,0,1,1) == 12);
  QVERIFY(tens.at(0,0,2,2) == 13);
  QVERIFY(tens.at(2,2,2,2) == 33);
  QVERIFY(tens.at(1,2,1,2) == 44);
  QVERIFY(tens.at(0,1,0,1) == 66);

  for(int p = 0; p < 3; p++) {
    for(int q = 0; q < 3; q++) {
      for(int r = 0; r < 3; r++) {
	for(int s = 0; s < 3; s++) {
	  QVERIFY(tens.at(p,q,r,s) == tens.at(q, p, r, s));
	  QVERIFY(tens.at(p,q,r,s) == tens.at(p, q, s, r));
	  QVERIFY(tens.at(p,q,r,s) == tens.at(r, s, p, q));
	}
      }
    }
  }
}

 QTEST_MAIN(TestUtil)
 #include "testutil.moc"

