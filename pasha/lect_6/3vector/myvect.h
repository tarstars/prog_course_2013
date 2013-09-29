#ifndef _MYVECT_
#define _MYVECT_

#include <iostream>

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
#endif
