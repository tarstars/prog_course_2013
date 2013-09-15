#include <iostream>
#include <complex>
#include "ao.h"

using namespace std;

template <typename T>
T one_step(const T &c, double dx, double x, double y, double q) {

	T k1 = c.deriv(x, y, q) * dx;
	T k2 = (c + k1*0.5).deriv(x + dx/2, y, q) * dx;
	T k3 = (c + k2*0.5).deriv(x + dx/2, y, q) * dx;
	T k4 = (c + k3).deriv(x + dx, y, q) * dx;
	
	return c + (k1 + k2*2 + k3*2 + k4) * (1.0 / 6);
}

int main(int argc, char ** argv) {
	AO c;
	double q = M_PI / (6320e-10) * sqrt((1200e-15) * 1 / 1e-2 / 5e-3);
	double x_max = 2 * M_PI / q;
	double dx = x_max / 100;
	double y_max = 10 * q; // расстройка
	double dy = y_max / 1000;
	for(double y = 0; y < y_max; y += dy) {
		for(double x = 0; x < x_max; x += dx) {
			c = one_step(c, dx, x, y, q);
			cout << c << " ";
		}
		cout << endl;
	}
}

// ./acoustooptic_obj > a.txt
// далее строим в матлабе (single_plot.m)