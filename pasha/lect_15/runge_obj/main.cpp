//решение дифф-ур методом Рунге-Кутта через наследование

#include <iostream>
#include "circlewalk.h"
#include "poly_eq.h"

using namespace std;

Solvable* one_step(Solvable* pSol, double dt) {
	Solvable *pk1 = pSol -> clone() -> derive() -> mult(dt);
	Solvable *pk2 = pk1 -> clone() -> mult(0.5) -> add(pSol) -> derive() -> mult(dt);
	Solvable *pk3 = pk2 -> clone() -> mult(0.5) -> add(pSol) -> derive() -> mult(dt);
	Solvable *pk4 = pk3 -> clone() -> add(pSol) -> derive() -> mult(dt);
	
	pk2 -> add(pk3) -> mult(2) -> add(pk1) -> add(pk4) -> mult(1.0/6) -> add(pSol);
	
	delete pk1;
	delete pk3;
	delete pk4;
	
	return pk2; //копировать по значению в pSol не получится, т.к. при этом будет происходить срезка: копируются только значения в базовом классе, а в производном - нет
}

int main(int argc, char ** argv) {
	Solvable *pSol = new circlewalk(); //solvable - скелет; circlewalk - внутренности
	
	double dt = 0.1;
	for(double t = 0; t < 6.3; t += dt) {
		Solvable *pSol_next = one_step(pSol, dt); //функции clone, mult, ... - смотрят на внутренности
		delete pSol;
		pSol = pSol_next;
		pSol -> print(cout);
	}
	
	delete pSol;
}