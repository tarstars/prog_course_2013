#ifndef _3VECTOR_
#define _3VECTOR_

#include <iostream>

class 3vector {
	double x,y,z;
public:
	3vector();
	3vector(double, double, double);
	friend std::ostream& operator<< (std::ostream&, const 3vector&);
	double& at(int);
	friend double& operator* (double);
	friend 3vector& operator+ (const 3vector&);
};
#endif