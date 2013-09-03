#include <iostream>
#include <string>

using namespace std;

template<typename Tanya>
Tanya sum(Tanya x, Tanya y) {
  return x + y;
}

template<int T>
void f() {
  cout << T << endl;
  f<T-1>();
}

template<>
void f<0>() {
  cout << 0 << endl;
}

template<int T>
int fact() {
  return T * fact<T-1>();
}

template<>
int fact<0>() {
  return 1;
}

void test_fact() {
    cout << "fact = " << fact<5>() << endl;
}

void test_f() {
  f<5>();
}

/*
string sum(string x, string y) {
  return x + " ura! " +  y;
  }*/

void test_sum() {
  string a("abc "), b("xyz ");
  cout << "sum = " << sum(5, 3) << endl;
  cout << "sum = " << sum(a, b) << endl;
}

class Ku {
public:
  Ku() {
    static int meter = 1;
    cout << meter << " Ku!" << endl;
    ++meter;
  }
};

void test_ku() {
  Ku a[50];
}

template<typename T>
class CoolArray {
  T *pDat;
public:
  CoolArray(int s) : pDat(new T[s]) {}
};

int main() {
  //test_ku();
  test_fact();
  return 0;
}
