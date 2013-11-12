#include <iostream>
#include <fstream>
#include <conio.h>
#include <vector>
#include <cmath>

#include "Vec3.h"
#include "Tensor4.h"
#include "matrix.h"
#include "util.h"
#include "polynom.h"
#include "SolPart.h"

using namespace std;
//_______________________________________________________________

int main() {

    //задать плоскость с помощью нормали
    //построить три пов-ти медленности
    //отсечь части, лежащие с той стороны куда смотрит нормаль
    //получится три чашечки

    /*Tensor4 c_ij = makeTetragonalTensor(5.6e10, 5.145e10, 2.2e10,
                                        10.6e10, 2.65e10, 6.6e10);

    ofstream sol_out("../crystal/sol.txt");
    //ofstream sol_out("../crystal/xy_plane.pov");

    for(int phi = 0; phi < 2*M_PI; phi += 0.001) {

        Vec3 n = Vec3(cos(phi), sin(phi), 0).normalized();
        vector<SolPart> sols(3);
        sols = solveChristoffel(c_ij, n);

        for(int i = 0; i < 3; ++i) {
            sol_out << 1.0 / sols[i].get_v() << " " ;
        }
        sol_out << phi << endl;
    }
    sol_out.close ();

    cout << "Ok" << endl;*/

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

    getch();
    return 1;
}
