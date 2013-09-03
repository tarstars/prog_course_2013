#include <iostream>
#include "matrix.h"

using namespace std;

void
test_dimensions1() {
  Matrix dat(5, 7);

  int real = dat.height();
  int expect = 5;
  if (real == expect) {
    cout << "OK" << endl;
  } else {
    cout << "FAIL: real = " << real << " expected = " << expect << endl;
  }
}

void
test_dimensions2() {
  Matrix dat(15, 7);

  int real = dat.height();
  int expect = 15;
  if (real == expect) {
    cout << "OK" << endl;
  } else {
    cout << "FAIL: real = " << real << " expected = " << expect << endl;
  }
}

void
test_dimensions3() {
  Matrix dat(15, 7);

  int real = dat.width();
  int expect = 7;
  if (real == expect) {
    cout << "OK" << endl;
  } else {
    cout << "FAIL: real = " << real << " expected = " << expect << endl;
  }
}

void
test_dimensions4() {
  Matrix dat(15, 17);

  int real = dat.width();
  int expect = 17;
  if (real == expect) {
    cout << "OK" << endl;
  } else {
    cout << "FAIL: real = " << real << " expected = " << expect << endl;
  }
}

int main() {
  test_dimensions1();
  test_dimensions2();
  test_dimensions3();
  test_dimensions4();
}
