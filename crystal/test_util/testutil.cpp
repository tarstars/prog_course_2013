#include "matrix.h"
#include <QtTest/QtTest>
#include "vec3.h"
#include "Tensor4.h"
#include "util.h"
#include "polynom.h"
#include "matrix.h"

class TestUtil: public QObject
{
  Q_OBJECT
  private slots:
  void testMakeTetragonalTensor();
  void testChristoffel();
  void testMatrixToPoly();
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

void
TestUtil::testChristoffel() {
  Tensor4 tens = makeTetragonalTensor(11, 12, 13, 33, 44, 66);
  Vec3 n(1, 0, 0);
  Matrix christ = christoffel(tens, n);

  QVERIFY(christ.Get(0, 0) == 11);
  QVERIFY(christ.Get(0, 1) == 0);
  QVERIFY(christ.Get(0, 2) == 0);

  QVERIFY(christ.Get(1, 0) == 0);
  QVERIFY(christ.Get(1, 1) == 66);
  QVERIFY(christ.Get(1, 2) == 0);

  QVERIFY(christ.Get(2, 0) == 0);
  QVERIFY(christ.Get(2, 1) == 0);
  QVERIFY(christ.Get(2, 2) == 44);
  
}

void
TestUtil::testMatrixToPoly(){
  Matrix mat(3,3);
  Polynom Pol;
  Pol = MatrixToPoly(mat);

  
  QVERIFY(Pol.get(0) == 1);
}

QTEST_MAIN(TestUtil)
#include "testutil.moc"

