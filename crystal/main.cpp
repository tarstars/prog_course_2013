#include "vec3.h"
#include "Tensor4.h"
#include "matrix.h"
#include "solpart.h"
#include "util.h"
#include <vector>

using namespace std;



int main() {
  Vec3 n=Vec3(1, 1, 0).normalized();
  Tensor4 tens = makeTetragonalTensor(5.6e10, 5.145e10, 2.2e10, 10.6e10, 2.65e10, 6.6e10);
  double rho = 5.96e3;
  Matrix chrMat = christoffel(tens, n);
  vector<SolPart> sols = solveChristoffel(chrMat, rho);
  for(size_t p = 0; p < sols.size(); ++p) {
    cout << (p + 1) << ") " << sols[p] << endl;
  }
  
  return 0;
}

//Андрей - solveChristoffel
//Настя - тесткейсы для новых функций
//Таня - eval, operator*, det
//CalcPol - Паша
