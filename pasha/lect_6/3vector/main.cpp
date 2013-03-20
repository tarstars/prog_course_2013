#include <iostream>
#include "3vector.h"
using namespace std;

int main() {
	double x,y,z;
	cout<<"Введите x y z: ";
	cin>>x>>y>>z;
	
	3vector r(x,y,z);
	cout<<"Вектор r: "<<r<<endl;
	cout<<"r(2)="<<3vector.at(2)<<endl;
	
	double a;
	cout>>"Введите a:";
	cin>>a;
	3vector t=r*a;
	cout<<"t=r*a="<<t<<endl;
	
	3vector y=r+t;
	cout<<"y=r+t="<<y<<endl;
	
	return 0;
}

