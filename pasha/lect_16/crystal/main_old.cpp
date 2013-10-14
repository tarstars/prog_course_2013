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

    Vec3 n(1, 1, 1);
    n.normalize();
    //cout << n.abs() << endl;

    Matrix Gamma_ij = christoffel(c_ij, n);
    cout << "christoffel(c_ij, n)" << endl;
    Gamma_ij.print();
    //cout << Gamma_ij.det();

    Polynom poly = Matrix2Poly(Gamma_ij);
    //cout << poly << endl << endl;

    vector<double> root = poly.solvePolynom(); //корни куб. ур-€
    cout << "roots of cubic equetion" << endl;
    cout << root[0] << "; " << root[1] << "; " << root[2] << endl << endl;

    vector<Matrix> G_root = eval(Gamma_ij, root);
    cout << "Matrices for each root" << endl;
    G_root[0].print();
    G_root[1].print();
    G_root[2].print();

    vector<Vec3> polariz = CalcPol(G_root); //пол€ризаци€
    cout << "Polarisations for each root" << endl;
    cout << polariz[0] << endl;
    cout << polariz[1] << endl;
    cout << polariz[2] << endl;

    getch();
    return 1;
}
