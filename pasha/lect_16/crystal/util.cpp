#include "Vec3.h"
#include "Tensor4.h"
#include "Mat3.h"
#include "util.h"

#include <cmath>

Vec3 makeVec3_norm(double x, double y, double z) {
    Vec3 new_vec3;
    double norm = sqrt(x*x + y*y + z*z);
    *new_vec3.get(0) = x/norm;
    *new_vec3.get(1) = y/norm;
    *new_vec3.get(2) = z/norm;
    return new_vec3;
}

//________________________________________________________

Tensor4 makeTensor4(double c11, double c12, double c13,
                    double c33, double c44, double c66) {
    Tensor4 new_tens;

    double* tens2 = new double[36]();
    tens2[0] = c11;  tens2[1] = c12;  tens2[2] = c13;
    tens2[6] = c12;  tens2[7] = c11;  tens2[8] = c13;
    tens2[12] = c13; tens2[13] = c13; tens2[14] = c33;
    tens2[21] = c44; tens2[28] = c44; tens2[35] = c66;

    int a=0, b;
    int i, j, k, l;
    for(int n=0; n<36; ++n) {

        if((n%6 == 0) && n!=0) a+=1;
        b = n - 6*a;

        if(a==0 || a==1 || a==2) i=a, j=a;
        if(a==3) i=1, j=2;
        if(a==4) i=0, j=2;
        if(a==5) i=0, j=1;

        if(b==0 || b==1 || b==2) k=b, l=b;
        if(b==3) k=1, l=2;
        if(b==4) k=0, l=2;
        if(b==5) k=0, l=1;

        *new_tens.get(i,j,k,l) =
                *new_tens.get(j,i,k,l) = *new_tens.get(i,j,l,k) =
                *new_tens.get(j,i,l,k) = *new_tens.get(k,l,i,j) =
                *new_tens.get(l,k,i,j) = *new_tens.get(l,k,j,i) =
                *new_tens.get(k,l,j,i) = tens2[b+6*a];
    }
    delete[] tens2;
    return new_tens;
}

//_________________________________________________________________

Mat3 christoffel(Tensor4 tens4, Vec3 n) {
    Mat3 new_matrix;
    //?_il= c_ijkl * n_j * n_k;
    for(int i=0; i<3; ++i) {
        for(int l=0; l<3; ++l) {
            for(int j=0; j<3; ++j) {
                for(int k=0; k<3; ++k) {
                    *new_matrix.get(i,l) +=
                            tens4.at(i,j,k,l) * n.at(j) * n.at(k);
                }
            }
        }
    }
    return new_matrix;
}

//_________________________________________________________________

/*vector<SolPart> solveChristoffel(Mat3 chrMat) {

}*/
