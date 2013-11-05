#pragma once
#include<vector>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

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

Matrix rotX(double a);
Matrix rotY(double a);
Matrix rotZ(double a);

int compareSolPart(const void * a, const void * b);

//povray stuff
#include <ostream>
#include <string>

class PovrayColor
{
    public:
        PovrayColor()
        {
            rgb[2] = rgb[1] = rgb[0] = 255;
        }

        PovrayColor(unsigned char r,
                    unsigned char g,
                    unsigned char b)
        {
            rgb[0]=r;
            rgb[1]=g;
            rgb[2]=b;
        }

        //accepts color in "#RRGGBB" format, defaults to white
        PovrayColor(std::string html);

        unsigned char Red() const { return rgb[0];}
        unsigned char Green() const { return rgb[1];}
        unsigned char Blue() const { return rgb[2];}

        float red() const { return rgb[0]/255.;}
        float green() const { return rgb[1]/255.;}
        float blue() const { return rgb[2]/255.;}
    private:
        unsigned char rgb[3];

};

std::ostream& operator <<(std::ostream& os, const PovrayColor& color);
/*
 * POVray coordinates: (y,z,-x)
 */
std::ostream& outputPovrayCoords(std::ostream& os, double x, double y, double z);
std::ostream& outputPovrayCoords(std::ostream& os, const Vec3& vec);

std::ostream& outputPovraySphere(std::ostream& os, const Vec3& vec,
                                 const PovrayColor& color = PovrayColor(127,127,127));
std::ostream& outputPovrayCylinder(std::ostream& os, const Vec3& base,
                                   const Vec3& cap, double radius,
                                   const PovrayColor& color = PovrayColor(127,127,127));


