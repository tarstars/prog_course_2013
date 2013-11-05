#include "matrix.h"
#include <QtTest/QtTest>
#include "vec3.h"
#include "Tensor4.h"
#include "util.h"
#include "polynom.h"
#include "matrix.h"
#include "solpart.h"

class TestUtil: public QObject
{
  Q_OBJECT
  private slots:
  void testMakeTetragonalTensor();
  void testChristoffel();
  void testMatrixToPoly();
  void testCalcPol00();
  void testCalcPol01();
  void testCalcPol02();
  void testCalcPol03();
  void testCalcPol04();
  void testsolveChris();
  void testPovrayColor();
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

Matrix fillMatrix(double a11, double a12, double a13,
		  double a21, double a22, double a23,
		  double a31, double a32, double a33
		  ) {
  Matrix mat(3,3);

  mat.Set(0, 0, a11); 
  mat.Set(0, 1, a12); 
  mat.Set(0, 2, a13); 

  mat.Set(1, 0, a21); 
  mat.Set(1, 1, a22); 
  mat.Set(1, 2, a23); 

  mat.Set(2, 0, a31); 
  mat.Set(2, 1, a32); 
  mat.Set(2, 2, a33); 

  return mat;
}

void
TestUtil::testCalcPol00() {
  Matrix mat = fillMatrix(
			  4, 6, 5, 
			  8, 8, 11, 
			  2, 1, 3);


  QVERIFY(mat.det() == 0);

  Vec3 a = CalcPol(mat);
  Vec3 res(13, -2, -8);
  res.normalize();

  for(int p = 0; p < 3; p++) {
    QVERIFY(a.at(p) == res.at(p));
  }
  
}

void
TestUtil::testCalcPol01() {
  Matrix mat = fillMatrix(
			  4, 6, 5, 
			  8, 12, 10, 
			  2, 1, 3);


  QVERIFY(mat.det() == 0);

  Vec3 a = CalcPol(mat);
  Vec3 res(13, -2, -8);
  res.normalize();

  for(int p = 0; p < 3; p++) {
    QVERIFY(a.at(p) == res.at(p));
  }
  
}

void
TestUtil::testCalcPol02() {
  Matrix mat = fillMatrix(
			  4, 6, 5, 
			  8, 8, 11, 
			  8, 12, 10);


  QVERIFY(mat.det() == 0);

  Vec3 a = CalcPol(mat);
  Vec3 res(13, -2, -8);
  res.normalize();

  for(int p = 0; p < 3; p++) {
    QVERIFY(a.at(p) == res.at(p));
  }
}

void
TestUtil::testCalcPol03() {
  Matrix mat = fillMatrix(
			  1, 6, 5, 
			  8, 12, 10, 
			  4, 6, 5);


  QVERIFY(mat.det() == 0);

  Vec3 a = CalcPol(mat);
  Vec3 res(13, -2, -8);
  res.normalize();

  for(int p = 0; p < 3; p++) {
    QVERIFY(a.at(p) == res.at(p));
  }
  
}

void
TestUtil::testCalcPol04() {
  Matrix mat = fillMatrix(
			  0, 0, 0, 
			  8, 8, 11, 
			  4, 6, 5);


  QVERIFY(mat.det() == 0);

  Vec3 a = CalcPol(mat);
  Vec3 res(13, -2, -8);
  res.normalize();

  for(int p = 0; p < 3; p++) {
    QVERIFY(a.at(p) == res.at(p));
  }
  
}

void TestUtil::testsolveChris(){
  Matrix mat = fillMatrix(
			  4, 6, 5, 
			  8, 8, 11, 
			  8, 12, 10);
  vector<SolPart> a;
  a = solveChristoffel(mat,6e3);
}

void TestUtil::testPovrayColor()
{
    PovrayColor color(2,3,4);
    QVERIFY(color.Red() == 2);
    QVERIFY(color.Green() == 3);
    QVERIFY(color.Blue() == 4);
    
    color = PovrayColor("#0AD345");
    QVERIFY(color.Red() == 0x0A);
    QVERIFY(color.Green() == 0xD3);
    QVERIFY(color.Blue() == 0x45);
    
    color = PovrayColor("#DF0ab4");
    QVERIFY(color.Red() == 0xDF);
    QVERIFY(color.Green() == 0x0A);
    QVERIFY(color.Blue() == 0xB4);
    
    color = PovrayColor("#hh00dd");
    QVERIFY(color.Red() == 255);
    QVERIFY(color.Green() == 255);
    QVERIFY(color.Blue() == 255);
}

QTEST_MAIN(TestUtil)
#include "testutil.moc"

