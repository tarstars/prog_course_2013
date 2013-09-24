#include <iostream>

#include "circle_walk.h"
#include "poly_eq.h"

using namespace std;

Solvable* one_step(Solvable* pSol, double dt) {
  Solvable *pk1 = pSol -> Clone() -> derive() -> mult(dt);
  Solvable *pk2 = pk1 -> Clone() -> mult(0.5) -> add(pSol) -> derive() -> mult(dt);
  Solvable *pk3 = pk2 -> Clone() -> mult(0.5) -> add(pSol) -> derive() -> mult(dt);
  Solvable *pk4 = pk3 -> Clone() -> add(pSol) -> derive() -> mult(dt);

  pk2->add(pk3)->mult(2)->add(pk1)->add(pk4)->mult(1.0/6)->add(pSol);

  delete pk1;
  delete pk3;
  delete pk4;

  return pk2;
}

int main(int argc, char ** argv) {
  Solvable *pSol = new CircleWalk();

  double dt = 0.1;
  for(double t = 0; t < 6.3; t += dt) {
    Solvable *pSol_next = one_step(pSol, dt);
    delete pSol;
    pSol = pSol_next;
    pSol -> Print(cout);
  }

  delete pSol;
}
