#pragma once

class Tensor4;
class Matrix;
class Vec3;
class Polynom;

Tensor4 makeTetragonalTensor(double c11, double c12, double c13,
                             double c33, double c44, double c66);

Matrix christoffel(const Tensor4& tens4, const Vec3& n);

Polynom Matrix2Poly(const Matrix& G);

Matrix eval(const Matrix& G, double root);

Vec3 CalcPol(Matrix G_root);
