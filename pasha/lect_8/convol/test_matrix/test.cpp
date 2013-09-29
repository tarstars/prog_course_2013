#include <complex>
#include <QtTest/QtTest>
#include "Matrix.h"

using namespace std;
class TestMatrix : public QObject { //наследование от класса QObject
	Q_OBJECT; //макроподстановка == define
private slots: //позволяет объектам обмениваться сообщениями
	void test_width();
	void test_content();
};

namespace QTest {
	template<>
	char* toString(const complex<double>& r) {
		QByteArray ba = "(" + QByteArray::number(real(r)) +
						"," + QByteArray::number(imag(r)) + ")";
		return qstrdup(ba.data());
	}
}

void
TestMatrix::test_width() {
	Matrix dat(5,7);
	QCOMPARE(dat.width(), 7);
	QCOMPARE(dat.height(), 5);
}

void
TestMatrix::test_content() {
	Matrix dat(15,17);
	complex<double> val1(3.14, 2.71);
	complex<double> val2(2.64, 4.61);
	dat.at(12,16)=val1;
	dat.at(13,16)=val2;
	QCOMPARE(dat.at(12,16), val1);
	QCOMPARE(dat.at(13,16), val2);
}

QTEST_MAIN(TestMatrix) //макрос, делающий ф-ию main, вызывающую все слоты
#include "test.moc"

// в .pro дописать: CONFIG += qtestlib
//					INCLUDEPATH += . .. (DEPENDPATH-аналогично)
//					SOURCES += test.cpp Matrix.cpp