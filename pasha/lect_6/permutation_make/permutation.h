#ifndef _PERMUTATION_
#define _PERMUTATION_

#include <iostream>

class permutation {
	int n, *pb;
public:
	permutation();
	permutation(int);
	friend std::ostream& operator<< (std::ostream&, const permutation&);
	void myswap(int, int);
	permutation operator* (const permutation&);
	permutation operator= (const permutation&);
	void next();
	~permutation();
};
#endif