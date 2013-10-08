#include "matrix.h"
#include "util.h"
#include "Tensor4.h"
#include "vec3.h"
#include "polynom.h"
//__________________________________________________________________

Tensor4 makeTetragonalTensor(double c11, double c12, double c13,
                             double c33, double c44, double c66) {
    Tensor4 new_tens;

    double tens2[6][6] = {
        {c11, c12, c13,   0,   0,   0},
        {c12, c11, c13,   0,   0,   0},
        {c13, c13, c33,   0,   0,   0},
        {  0,   0,   0, c44,   0,   0},
        {  0,   0,   0,   0, c44,   0},
        {  0,   0,   0,   0,   0, c66}};

    double mat[3][3] = {
        {1, 6, 5},
        {6, 2, 4},
        {5, 4, 3}};

    for(int i=0; i<3; ++i) {
        for(int j=0; j<3; ++j) {
            for(int k=0; k<3; ++k) {
                for(int l=0; l<3; ++l) {
                    int a = mat[i][j];
                    int b = mat[k][l];
                    double v = tens2[a-1][b-1];
                    new_tens.set(i,j,k,l,v);
                }
            }

        }
    }
    return new_tens;
}
//__________________________________________________________________

Matrix christoffel(const Tensor4& tens4, const Vec3& n) {

    Matrix new_matrix(3,3);
  
    //\Gamma_il= c_ijkl * n_j * n_k;
    for(int i=0; i<3; ++i) {
        for(int l=0; l<3; ++l) {
            double val = 0;
            for(int j=0; j<3; ++j) {
                for(int k=0; k<3; ++k) {
                    val += tens4.at(i,j,k,l) * n.at(j) * n.at(k);
                }
            }
            new_matrix.Set(i, l, val);
        }
    }
  
    return new_matrix;
}
//__________________________________________________________________

Polynom Matrix2Poly(const Matrix& G) {

    double a0, a1, a2, a3;
    double G00 = G.Get(0,0);
    double G01 = G.Get(0,1);
    double G02 = G.Get(0,2);
    double G11 = G.Get(1,1);
    double G12 = G.Get(1,2);
    double G22 = G.Get(2,2);


    a3 = -1.0;
    a2 = G00 + G11 + G22;
    a1 = G01*G01 + G02*G02 + G12*G12 -
         G00*G11 - G00*G22 - G11*G22;
    a0 = - G22*G01*G01 + 2*G01*G02*G12 - G11*G02*G02
         - G00*G12*G12 + G00*G11*G22;

    Polynom new_pol(a3, a2, a1, a0);

    return new_pol;
}
//________________________________________________________________

Matrix eval(const Matrix& G, double root) {
    Matrix new_G = G;
    double val;
    for(int i=0; i<3; ++i) {
        val = G.Get(i,i) - root;
        new_G.Set(i,i,val);
    }

    return new_G;
}
//_________________________________________________________________

Vec3 CalcPol(Matrix G) {
    Vec3 a0, a1, a2;

    a0.set(0, G.Get(0,1)*G.Get(1,2) -
              G.Get(1,1)*G.Get(0,2));
    a0.set(1, G.Get(1,0)*G.Get(0,2) -
              G.Get(0,0)*G.Get(1,2));
    a0.set(2, G.Get(0,0)*G.Get(1,1) -
              G.Get(1,0)*G.Get(0,1));

    a1.set(0, G.Get(1,1)*G.Get(2,2) -
              G.Get(2,1)*G.Get(1,2));
    a1.set(1, G.Get(2,0)*G.Get(1,2) -
              G.Get(1,0)*G.Get(2,2));
    a1.set(2, G.Get(1,0)*G.Get(2,1) -
              G.Get(2,0)*G.Get(1,1));

    a2.set(0, G.Get(0,1)*G.Get(2,2) -
              G.Get(2,1)*G.Get(0,2));
    a2.set(1, G.Get(2,0)*G.Get(0,2) -
              G.Get(0,0)*G.Get(2,2));
    a2.set(2, G.Get(0,0)*G.Get(2,1) -
              G.Get(2,0)*G.Get(0,1));

    double norm[3] = {a0.abs(), a1.abs(), a2.abs()};
    double max_norm = norm[0];
    double n = 0;
    for(int i=1; i<=2; ++i) {
        if(max_norm < norm[i]) {
            max_norm = norm[i];
            n += 1;
        }
    }

    if(n==0) return a0.normalized();
    if(n==1) return a1.normalized();
    if(n==2) return a2.normalized();
}
