#include "vec3.h"
#include "Tensor4.h"
#include "matrix.h"
#include "util.h"

#include <vector>

using namespace std;

class SolPart {
  double v;
  Vec3 q;
public:
  SolPart(){}
  SolPart(double x, double y, double z) : q(x, y, z) {}
};

int main() {
  Vec3 n=Vec3(1, 1, 0).normalized();
  Tensor4 tens = makeTetragonalTensor(5.6e10, 5.145e10, 2.2e10, 10.6e10, 2.65e10, 6.6e10);
  Matrix chrMat = christoffel(tens, n);
  vector<SolPart> sols(3); // = solveChristoffel(chrMat);
  SolPart a = sols[1];
}

//Андрей - solveChristoffel
//Настя - тесткейсы для новых функций
//Таня - eval, operator*, det
//CalcPol - Паша
