#include "matrix.h"
#include "util.h"
#include "Tensor4.h"
#include "vec3.h"
#include "polynom.h"
#include "SolPart.h"
#include <cmath>
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

Polynom Matrix2Poly(const Matrix& mat) {
    Matrix mat2 = mat*mat;
    Polynom Pol(1,2,3,4);
    double a1,a2,a3,a4; // polynomial coefficents at x^3, x^2, x^1, x^0;

    a1 = -1;
    a2 = 1*mat.trace();
    a3 = 0.5*mat2.trace() - 0.5*mat.trace()*mat.trace();
    a4 = 1*mat.det();
    Pol.set(a1,a2,a3,a4);

    return Pol;
}
//________________________________________________________________

vector<Matrix> eval(const Matrix& M, const vector<double>& root) {
    vector<Matrix> new_M(3,M);
    double val;
    for(int i=0; i<3; ++i) {
        for(int j=0; j<3; ++j) {
            val = M.Get(j,j) - root[i];
            new_M[i].Set(j,j,val);
        }
    }
    return new_M;
}
//________________________________________________________________

vector<Vec3> CalcPol(const vector<Matrix>& G) {
    vector<Vec3> a0(3), a1(3), a2(3), a(3);
    vector<Vec3> v0(3), v1(3), v2(3);

    for(int i=0; i<3; ++i) {
        for(int j=0; j<3; ++j) {
            a0[i].set(j, G[i].Get(0,j));
            a1[i].set(j, G[i].Get(1,j));
            a2[i].set(j, G[i].Get(2,j));
        }
        v0[i] = a0[i] * a1[i];
        v1[i] = a0[i] * a2[i];
        v2[i] = a1[i] * a2[i];
        if((v0[i].abs() >= v1[i].abs()) &&
           (v0[i].abs() >= v2[i].abs()))
                a[i] = v0[i].normalized();
        else if((v1[i].abs() >= v0[i].abs()) &&
                (v1[i].abs() >= v2[i].abs()))
                a[i] = v1[i].normalized();
        else
                a[i] = v2[i].normalized();
    }
    return a;
}
//_________________________________________________________________

vector<SolPart> solveChristoffel(const Tensor4& c_ij, const Vec3& n) {
    Matrix Gamma_ij = christoffel(c_ij, n);
    Polynom poly = Matrix2Poly(Gamma_ij);
    vector<double> root = poly.solvePolynom(); //корни куб. ур-€
    vector<Matrix> G_root = eval(Gamma_ij, root);
    vector<Vec3> polariz = CalcPol(G_root); //пол€ризаци€
    vector<SolPart> s(3);
    for(int i = 0; i < 3; ++i) {
        s[i] = SolPart(sqrt(root[i]/5.96e3), polariz[i]);
    }

    /*cout << "christoffel(c_ij, n)" << endl;
    Gamma_ij.print();
    cout << "roots of cubic equetion" << endl;
    cout << root[0] << "; " << root[1] << "; " << root[2] << endl << endl;
    cout << "Matrices for each root" << endl;
    G_root[0].print();
    G_root[1].print();
    G_root[2].print();
    cout << "Polarisations for each root" << endl;
    cout << polariz[0] << endl;
    cout << polariz[1] << endl;
    cout << polariz[2] << endl;*/

    return s;
}
//_____________________________________________________________________

Matrix Rot_x(double phi)
{
  Matrix dat(3,3);

  dat.Set(0, 0, 1);
  dat.Set(0, 1, 0);
  dat.Set(0, 2, 0);

  dat.Set(1, 0, 0);
  dat.Set(1, 1, cos(phi));
  dat.Set(1, 2, sin(phi));

  dat.Set(2, 0, 0);
  dat.Set(2, 1, -sin(phi));
  dat.Set(2, 2, cos(phi));

return dat;
}
//_____________________________

Matrix Rot_y(double phi)
{
  Matrix dat(3,3);

  dat.Set(0, 0, cos(phi));
  dat.Set(0, 1, 0);
  dat.Set(0, 2, -sin(phi));

  dat.Set(1, 0, 0);
  dat.Set(1, 1, 1);
  dat.Set(1, 2, 0);

  dat.Set(2, 0, sin(phi));
  dat.Set(2, 1, 0);
  dat.Set(2, 2, cos(phi));

return dat;
}
//____________________________

Matrix Rot_z(double phi)
{
  Matrix dat(3,3);

  dat.Set(0, 0, cos(phi));
  dat.Set(0, 1, sin(phi));
  dat.Set(0, 2, 0);

  dat.Set(1, 0, -sin(phi));
  dat.Set(1, 1, cos(phi));
  dat.Set(1, 2, 0);

  dat.Set(2, 0, 0);
  dat.Set(2, 1, 0);
  dat.Set(2, 2, 1);

return dat;
}
//__________________________________________________________________
