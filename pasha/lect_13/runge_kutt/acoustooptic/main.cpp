//решение Рунге-Кутта через указатель на ф-ию c'=f(c,x,y)
//уравнение связанных мод (физ. основы АО - стр.42)

#include <iostream>
#include <complex>
#include <vector>
#include <cmath>
using namespace std;

vector<complex<double> > init() {
	vector<complex<double> > c(2);
	c[0] = 1;
	c[1] = 0;
	return c;
}

vector<complex<double> > f(const vector<complex<double> > &c_prev, double x, double y) {
	double q = M_PI / (6320e-10) * sqrt((1200e-15) * 1 / 1e-2 / 5e-3); //max(x) = 1e-2
	complex<double> i(0,1);  //мнимая единица
	vector<complex<double> > c_new(2);
	c_new[0] = c_prev[1] * (-q/2 * exp(i*y*x));
	c_new[1] = c_prev[0] * (q/2 * exp(-i*y*x));
	return c_new;
}

ostream&
operator<<(ostream& os, const vector<complex<double> > &c) {
	for(int i=0; i < 2; ++i) {
		os << c[i] << " ";
	}
	return os;
}

vector<complex<double> > operator*(const vector<complex<double> > &c_left,
								   const complex<double> &number) {
	vector<complex<double> > c(c_left);  //тоже самое, что и: c = c_left
	
	for(int t=0; t < 2; ++t) {
		c[t] *= number;
	}
	return c;
}

vector<complex<double> > operator+(const vector<complex<double> > &c_left,
								   const vector<complex<double> > &c_right) {
	
	vector<complex<double> > c(c_left);
	
	for(int t=0; t < 2; ++t) {
		c[t] += c_right[t];
	}
	return c;
}

vector<complex<double> > one_step(std::vector<std::complex<double> > (*pf)(const std::vector<std::complex<double> >&, double, double), const vector<complex<double> > &c_prev, double dx, double x, double y) {

	vector<complex<double> > k1 = pf(c_prev, x, y) * dx;
	vector<complex<double> > k2 = pf(c_prev + k1*0.5, x + dx/2, y) * dx;
	vector<complex<double> > k3 = pf(c_prev + k2*0.5, x + dx/2, y) * dx;
	vector<complex<double> > k4 = pf(c_prev + k3, x + dx, y) * dx;
	
	return c_prev + (k1 + k2*2 + k3*2 + k4) * (1.0 / 6);
}

void calculation(){
	
	vector<complex<double> > c = init();
	
	double x_max = 1e-2; //длина АО взаимодействия
	double dx = x_max / 1000;
	double y = 0.6*M_PI / x_max; // расстройка
	for(double x = 0; x < x_max; x += dx) {
		c = one_step(f, c, dx, x, y);
		double q = M_PI / (6320e-10) * sqrt((1200e-15) * 1 / 1e-2 / 5e-3);
		cout << x*q/M_PI << " " << abs(c[0])*abs(c[0]) << " " << abs(c[1])*abs(c[1]) << endl;
	}
}

int main() {
	calculation();
}

// g++ main.cpp -o prog
// ./prog > a.txt
// далее строим в матлабе (single_plot.m)