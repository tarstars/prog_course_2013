#pragma once

Vec3 makeVec3_norm(double, double, double);

Tensor4 makeTensor4(double, double, double,
                    double, double, double);

Mat3 christoffel(Tensor4, Vec3);

//vector<SolPart> solveChristoffel(Mat3);
