#pragma once

#include <iostream>
#include <vector>

class Tensor4 {
	std::vector<double> v;
	void checkRE(int i, int j, int k, int l) const {
		if( (i < 0 || i > 2) || 
			(j < 0 || j > 2) || 
			(k < 0 || k > 2) || 
			(l < 0 || l > 2) )
			throw RangeErr();
	}
public:
	class RangeErr {};

    Tensor4();
    void set(int i, int j, int k, int l, double val);
    double at(int i, int j, int k, int l) const;
    friend std::ostream& operator <<(std::ostream& os, const Tensor4& t);
};
