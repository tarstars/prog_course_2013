#include <iostream>
#include<stdio.h>
#include<conio.h>

#include "Vec3.h"
#include "Tensor4.h"
#include "Mat3.h"
#include "util.h"

using namespace std;

int main() {
    Vec3 n = makeVec3_norm(1,0,0);
    Tensor4 tens4 = makeTensor4(5.6e10, 5.145e10, 2.2e10, 10.6e10, 2.65e10, 6.6e10);
    Mat3 chrMat4 = christoffel(tens4, n);
    //Poly pol = Matrix2Poly(chrMat4);
    //Polinomial::all_roots; //корни куб. ур.
    //eval(Matrix, root)
    //vecPolarization = calcPol(Matrix); //пол€ризаци€
    //det()=0 => вектора строк кристоффел€ - в одной плоскости
    //векторное произведение -> max

    //cout << n.at(0) << "; " << n.at(1) << "; " <<n.at(2) << endl;
    //cout << tens4.at(0,0,1,1) << endl;
    cout << chrMat4.at(0,0) << endl;
    getch();
}
