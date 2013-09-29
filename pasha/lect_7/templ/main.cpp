#include <iostream>
#include <string>

using namespace std;

template<typename T>
T sum(T x, T y) {
	return x+y;
}

template<int n>
int fact() {
	return n*fact<n-1 //считается на этапе компиляции !!!
}

template<>
int fact<0>() { //конкретное правило => ограничение рекурсии
	return 1;
}

void test_fact() {
	cout<<"fact="<<fact<5>()<<endl; // => n=5;
}

void test_sum() {
	string a("abc "), b("tre");
	cout<<"sum="<<sum(a,b)<<endl;
	cout<<"sum="<<sum(5,3)<<endl;
}

class ku {
public:
	ku() {
		static int n=1;			//значение не теряется при выходе из ф-ии
		cout<<n<<"q ";
		++n;
	}
};

void test_q() {
	ku a[50];
}

template<typename T>
class coolarr { 		//семейство классов
	T *p;
public:
	coolarr(int n): p(new T[n]) {}
};

int main() {
	test_q();
	cout<<endl;
	test_fact();
	return 0;
}

