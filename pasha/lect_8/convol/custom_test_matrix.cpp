#include <iostream>
#include "Matrix.h"
using namespace std;

void test_dimentions1() {
	int expect= 5, expectw= 7;
	Matrix dat(expect,expectw);
	int real = dat.height();
	if(real==expect) {
		cout << "Ok" << endl;
	}
	else {
		cout << "Fail: real = " << real << "; expected = " << expect << endl;
	}
}

void test_dimentions2() {
	int expecth= 5, expect= 7;
	Matrix dat(expecth,expect);
	int real = dat.width();
	if(real==expect) {
		cout << "Ok" << endl;
	}
	else {
		cout << "Fail: real = " << real << "; expected = " << expect << endl;
	}
}


int main() {
	test_dimentions1();
	test_dimentions2();
}