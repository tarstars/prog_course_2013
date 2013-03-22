#ifndef _PERMUTATION_
#define _PERMUTATION_

#include <iostream>

class permutation {
	int n, *pdat, k;
public:
	permutation();
	permutation(int, int*);
	friend std::ostream& operator<< (std::ostream&, const permutation&);
	void swap(int, int);
	void next();
	permutation& operator* (double);
};
#endif