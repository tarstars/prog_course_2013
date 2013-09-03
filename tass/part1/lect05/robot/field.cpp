#include <iostream>

#include "field.h"

using namespace std;

Field::Field(int nn) : n(nn), dat(n * n, '.') {

}

char&
Field::at(int p, int q) {
  return dat[p * n + q];
}

void
Field::print(ostream& os, const Robot& r) {
  //направление изменения p, q в циклах
  //are_you_here(p, q)
  //Robot::get_symb
}
