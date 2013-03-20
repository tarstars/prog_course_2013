#include <iostream>
#include "myvect.h"
using namespace std;

int main() {
	double x,y,z;
	cout<<"Введите x y z: ";
	cin>>x>>y>>z;
	
	myvect r(x,y,z);
	cout<<"Вектор r: "<<r<<endl;
	//cout<<"r_2="<<r_2<<endl;
	
	double a;
	cout<<"Введите a:";
	cin>>a;
	myvect t=r*a;
	cout<<"t=r*a="<<t<<endl;
	
	myvect e=r+t;
	cout<<"e=r+t"<<e<<endl;
	
	return 0;
}

