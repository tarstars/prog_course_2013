//решение дифф-ур методом Рунге-Кутта через наследование

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

void testVirt(Solvable* pSol) {
	double dt = 0.1;
	Solvable *pk1 = pSol -> clone() -> derive() -> mult(dt);
	Solvable *pk2 = pk1 -> clone() -> mult(0.5) -> add(pSol) -> derive() -> mult(dt);
	Solvable *pk3 = pk2 -> clone() -> mult(0.5) -> add(pSol) -> derive() -> mult(dt);
	Solvable *pk4 = pk3 -> clone() -> add(pSol) -> derive() -> mult(dt);
	
	pk2 -> add(pk3) -> mult(2) -> add(pk1) -> add(pk4) -> mult(1.0/6) -> add(pSol);
	
	delete pk1;
	delete pk3;
	delete pk4;
	
	return pk2;
}

int main(int argc, char ** argv) {
	Solvable* pSol = new circlewalk();
	testVirt(pSol);
	delete pSol;
}