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

	Tensor4() : v(81) {}
	Tensor4(const Tensor4& t) : v(t.v) {}
	Tensor4& operator =(const Tensor4& t) {
		if(&t == this)
			return *this;
		v.clear();
		v = t.v;
		return *this;
	}
	void set(int i, int j, int k, int l, double x) {
		checkRE(i, j, k, l);
		v[27*i + 9*j + 3*k + l] = x;
	}
	double at(int i, int j, int k, int l) const {
		checkRE(i, j, k, l);
		return v[27*i + 9*j + 3*k + l];
	}
	double& at(int i, int j, int k, int l) {
		checkRE(i, j, k, l);
		return v[27*i + 9*j + 3*k + l];
	}
	friend std::ostream& operator <<(std::ostream& os, const Tensor4& t);
};