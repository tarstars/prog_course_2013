#include "field.h"

Field::Field(int nn) : n(nn), dat(n * n, '.') {

}

char&
Field::at(int p, int q) {
  return dat[p * n + q];
}
