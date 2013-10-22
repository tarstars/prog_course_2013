#include "vec3.h"
#include "Tensor4.h"
#include "matrix.h"
#include "util.h"
#include "solpart.h"
#include <vector>
#include <fstream>

#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

using namespace std;

int main()
{
  Vec3 n;
  Tensor4 tens = makeTetragonalTensor(5.6e10, 5.145e10, 2.2e10, 10.6e10, 2.65e10, 6.6e10);
  double rho = 5.96e3;
  vector<SolPart> sols;

  ofstream povfile;
  povfile.open("crystal.pov",ofstream::out);
  povfile<<"#version 3.7;\n\nglobal_settings {assumed_gamma 1.0}\n\n";
  povfile<<"camera {\n    location <10,15,10>\n    look_at <0,0,0>\n    angle 30\n}\n\n";
  povfile<<"light_source {\n    <-10,10,10>\n    color <1, 1, 1>\n}\n\n";

  double r,x,y;
  for(double z = -1;z<=1;z+=0.02)
  {
    for(int k=0;k<360;++k)
    {
        r = sqrt(1-z*z);
        x = r*cos(2*M_PI*k/360.);
        y = r*sin(2*M_PI*k/360.);
        n = Vec3(x,y,z).normalized();
        Matrix chrMat = christoffel(tens, n);
        sols = solveChristoffel(chrMat,rho);
        for(int l=0;l<sols.size();++l)
        {
            povfile<<"sphere {\n    <"<<sols.at(l).getVec().at(1)<<
                     ","<<sols.at(l).getVec().at(2)<<
                     ","<<-1*sols.at(l).getVec().at(0)<<">, 1\n"
                     "pigment { rgb<0.5,0.5,0.5> }\n"
                     "    finish {\n        ambient .2\n        diffuse .6\n        specular .75\n"
                     "        roughness .001\n    }\n}\n\n";
        }
    }
  }

  povfile.close();
  return 0;
}
