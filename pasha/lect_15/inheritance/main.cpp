#include <iostream>
#include "a.h"
#include "a1.h"
#include "a2.h"

//A - родительский, а А1 и А2 - дочерние классы
//хотим вызывать ф-ию eval в зависимости от класса

using namespace std;

int main() {

	A* pworker;
	
	int c;
	cin >> c;
	if (c == 0) {
		pworker = new A1;
	}
	else {
		pworker = new A2;
	}
	
	cout << "a: " << pworker->eval(1) << endl;
	
	delete pworker;
}