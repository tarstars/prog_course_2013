#include <QtTest/QtTest>
#include "vec3.h"

class TestVec3: public QObject
{
  Q_OBJECT
  private slots:
  void setGet();
};

void TestVec3::setGet()
{
  Vec3 dat;
  
  dat.set(0, 5);
  dat.set(1, 15);
  dat.set(2, 25);

  QVERIFY(dat.at(0) == 5);
  QVERIFY(dat.at(1) == 15);
  QVERIFY(dat.at(2) == 25);
}

 QTEST_MAIN(TestVec3)
 #include "testvec3.moc"

