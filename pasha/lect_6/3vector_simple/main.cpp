#include <iostream>
using namespace std;

class myvect {
	double x,y,z;
public:
	myvect();
	myvect(double, double, double);
	friend std::ostream& operator<< (std::ostream&, const myvect&);
	friend double operator_ (int);
	friend myvect operator* (const myvect, double);
	friend myvect operator+ (const myvect, const myvect);
};
//_________________________________________________

myvect::
myvect(): x(0), y(0), z(0) {}

myvect::
myvect(double a, double b, double c): x(a), y(b), z(c) {}

ostream&
operator<< (ostream& os, const myvect& r) {
	return os << "(" << r.x << ", "<< r.y << ", "<<r.z<<")";
}

/*double 
operator_ (const myvect r, int i) {
	if(i==1) {return r.x;}
	if(i==2) {return r.y;}
	if(i==3) {return r.z;}
}*/

myvect
operator* (const myvect r, double a) {
	myvect q(r.x*a, r.y*a, r.z*a);
	return q;
}

myvect
operator+ (const myvect l, const myvect r) {
	myvect q(l.x+r.x, l.y+r.y, l.z+r.z);
	return q;
}
//______________________________________________

int main() {
	double x,y,z;
	cout<<"Введите x y z: ";
	cin>>x>>y>>z;
	
	myvect r(x,y,z);
	cout<<"Вектор r: "<<r<<endl;
	//cout<<"r_2="<<r_2<<endl;
	
	double a;
	cout<<"Введите a: ";
	cin>>a;
	myvect t=r*a;
	cout<<"t = r * a = "<<t<<endl;
	
	myvect e=r+t;
	cout<<"e = r + t = "<<e<<endl;
	
	return 0;
}

