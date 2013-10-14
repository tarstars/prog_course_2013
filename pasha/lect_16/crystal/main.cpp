#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <vector>

#include "Vec3.h"
#include "Tensor4.h"
#include "matrix.h"
#include "util.h"
#include "polynom.h"
#include "SolPart.h"

using namespace std;

int main() {

    Tensor4 c_ij = makeTetragonalTensor(11, 12, 13, 33, 44, 66);

    Vec3 n = Vec3(1, 1, 0).normalized();

    vector<SolPart> sols(3);
    sols = solveChristoffel(c_ij, n);
    cout << endl << endl;
    for(int i = 0; i < 3; ++i) {
        cout << i << " pair:" << endl << sols[i];
        cout << endl << endl;
    }

    getch();
    return 1;
}
