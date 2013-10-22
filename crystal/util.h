#pragma once
#include<vector>

class Tensor4;
class Matrix;
class Vec3;
class Polynom;
class SolPart;


Tensor4 makeTetragonalTensor(double c11, double c12, double c13, double c33, double c44, double c66);

Matrix christoffel(const Tensor4& tens4, const Vec3& n);

Polynom MatrixToPoly(const Matrix&);

Vec3 CalcPol(const Matrix& G);

vector<SolPart> solveChristoffel(const Matrix& chrMat, double rho);
