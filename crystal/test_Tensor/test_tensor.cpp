#include <QtTest/QtTest>
#include "matrix.h"
#include "Tensor4.h"

using namespace std;
class TestTensor: public QObject
{
  Q_OBJECT
  private slots:
  void Rot();
};

void TestTensor::Rot()
{
  Tensor4 T;
  Matrix m(3,3);
  T.tensorRot(m);
  }

 QTEST_MAIN(TestTensor)
 #include "test_tensor.moc"

