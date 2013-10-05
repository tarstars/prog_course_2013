#include <QtTest/QtTest>
#include "polynom.h"
#include<cmath>
#include <vector>
using namespace std;
class TestPolynom: public QObject
{
  Q_OBJECT
  private slots:
  void setGet();
};

void TestPolynom::setGet()
{
  vector<double> roots(3,0);
  Polynom Pol;
  double eps = 0.00000001;
  Pol.set(1,-7,11,-5);

  roots = Pol.solvePolynom();
  QVERIFY(abs(roots[0]-5)<eps);
  QVERIFY(abs(roots[1]-1)<eps);
  QVERIFY(abs(roots[2]-1)<eps);

  Pol.set(4,-7,11,-5);
  roots = Pol.solvePolynom();
  QVERIFY(roots[0] == 0);
  QVERIFY(roots[1]== 0);
  QVERIFY(roots[2] == 0);

  Pol.set(1,-9,-46,120);
  cout<<roots[0]<<' '<<roots[1]<<' '<<roots[2]<<' '<<endl;
  QVERIFY(abs(roots[0]+5)<eps );
  QVERIFY(abs(roots[1]-12)<eps);
  QVERIFY(abs(roots[2]-2) < eps );
}

 QTEST_MAIN(TestPolynom)
 #include "testpolynom.moc"

