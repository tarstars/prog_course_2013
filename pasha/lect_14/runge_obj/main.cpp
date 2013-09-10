//решение Рунге-Кутта через структуры [x,y] вместо vector
//перегрузка ф-ии one_step() или через template

//poly_eq: z' = z^2  =>  z = -1/(t+t0)
//circlewalk: x'=-y; y'=x  =>  движение по окружности

#include <iostream>
#include "circlewalk.h"
#include "poly_eq.h"

using namespace std;

template <typename T>
T one_step(const T &zp, double dt, double t) {

	T k1 = zp.deriv(t) * dt;
	T k2 = (zp + k1*0.5).deriv(t + dt/2) * dt;
	T k3 = (zp + k2*0.5).deriv(t + dt/2) * dt;
	T k4 = (zp + k3).deriv(t + dt) * dt;
	
	return zp + (k1 + k2*2 + k3*2 + k4) * (1.0 / 6);
}

int main(int argc, char ** argv) {
	double dt = 0.1;
	//circlewalk z;
	PolyEq z;
	for(double t=0; t < 6.0; t+=dt) {
		z = one_step(z, dt, t);
		cout << t << " " << z << endl;
	}
}