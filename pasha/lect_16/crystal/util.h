#pragma once
#include <vector>

class Tensor4;
class Matrix;
class Vec3;
class Polynom;
class SolPart;

Tensor4 makeTetragonalTensor(double c11, double c12, double c13,
                             double c33, double c44, double c66);

Matrix christoffel(const Tensor4& tens4, const Vec3& n);

Polynom Matrix2Poly(const Matrix& G);

vector<Matrix> eval(const Matrix& G, const vector<double>& root);

vector<Vec3> CalcPol(const vector<Matrix> &G_root);

vector<SolPart> solveChristoffel(const Tensor4& c_ij, const Vec3& n);

Matrix rot_x(double phi);
Matrix rot_y(double phi);
Matrix rot_z(double phi);
