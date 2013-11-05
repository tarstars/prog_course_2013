#include "vec3.h"
#include "Tensor4.h"
#include "matrix.h"
#include "solpart.h"
#include "util.h"

#include <cmath>
#include <vector>

using namespace std;

void testPlaneSlice() {
  Tensor4 tens = makeTetragonalTensor(5.6e10, 5.145e10, 2.2e10, 10.6e10, 2.65e10, 6.6e10);
  double rho = 5.96e3;

  for(double phi = 0; phi < 2 * M_PI; phi += 0.01) {
    Vec3 n=Vec3(cos(phi), sin(phi), 0).normalized();
    Matrix chrMat = christoffel(tens, n);
    vector<SolPart> sols = solveChristoffel(chrMat, rho);
    for(size_t p = 0; p < sols.size(); ++p) {
      double s = 1000 / sols[p].getV();
      Vec3 rad = n * s;
      cout << "sphere{<" << rad.at(0) << ", " << rad.at(2) << ", " << rad.at(1) << "> 0.01 pigment { color<0, 0, 1> }}" << endl;
    }
  }
}

int main() {
  //testSlice();
  
  return 0;
}

//Паша: нарисовать поляризации
//Андрей: фильтровать по модам
//Настя: попробовать повернуть картинку
//Дима: сделать моды разными цветами полностью отрисованные поверхности медленности шариками, сечение плоскостью. Плоскость поворачивается
//Таня: дописать бейсик с рэгекспами, чтобы рисовал линии
//
