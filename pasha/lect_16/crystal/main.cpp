#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <vector>

#include "Vec3.h"
#include "Tensor4.h"
#include "matrix.h"
#include "util.h"
#include "polynom.h"

using namespace std;

int main() {
    Tensor4 c_ij = makeTetragonalTensor(11, 12, 13, 33, 44, 66);
    //cout << tens;

    Vec3 n(1, 1, 0);
    n.normalized();
    //cout << n.abs() << endl;

    Matrix Gamma_ij = christoffel(c_ij, n);
    //Gamma_ij.print();

    Polynom poly = Matrix2Poly(Gamma_ij);
    //cout << pol << endl << endl;

    double* root = poly.solvePolynom(); //корни куб. ур-я
    //cout << root[0] << "; " << root[1] << "; " << root[2] << endl;

    Matrix G_root = eval(Gamma_ij, root[0]);
    G_root.print();

    Vec3 polariz = CalcPol(G_root); //поляризация
    cout << polariz << endl;

    //det()=0 => вектора строк матрицы лежат в одной плоскости
    //векторное произведение -> max

    getch();
    return 1;
}
