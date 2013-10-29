#include "vec3.h"
#include "Tensor4.h"
#include "matrix.h"
#include "util.h"
#include "solpart.h"
#include <vector>
#include <fstream>

#include <math.h>
#include <string.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#include "povray_templates.h"

using namespace std;


/*
 * POVray coordinates: (y,z,-x)
 */

ostream& outputCoords(ostream& os, double x, double y, double z)
{
    return os<<"<"<<y<<","<<z<<","<<-1*x<<">";
}

ostream& outputCoords(ostream& os, const Vec3& vec)
{
    return os<<"<"<<vec.at(1)<<","<<vec.at(2)<<","<<(-1*vec.at(0))<<">";
}

ostream& outputSphere(ostream& os, const Vec3& vec)
{
    os<<"sphere {\n    ";
    outputCoords(os,vec);
    os<<", 0.04\npigment { rgb<0.9,0.1,0.1> }\n"
             "    finish {\n        ambient .2\n        diffuse .6\n        specular .75\n"
             "        roughness .001\n    }\n}\n\n";
    return os;
}

void test_cut(ostream& os, const Vec3& vec)
{
  Vec3 n = vec.normalized();
    Tensor4 tens = makeTetragonalTensor(5.6e10, 5.145e10, 2.2e10, 10.6e10, 2.65e10, 6.6e10);
    double rho = 5.96e3;
    Matrix chrMat = christoffel(tens, n);
    vector<SolPart> sols = solveChristoffel(chrMat,rho);

    for(size_t l=0;l<sols.size();++l)
    {
        Vec3 speed(2000*n.at(0)/sols.at(l).getV(),
                   2000*n.at(1)/sols.at(l).getV(),
                   2000*n.at(2)/sols.at(l).getV());

        outputSphere(os,speed);
    }
}

void test_cuts(const char* filebase)
{
    char fname[256];
    memset(fname,0,sizeof(fname));
    strcat(fname,filebase);
    strcat(fname,".pov");
    ofstream povfile;
    povfile.open(fname,ofstream::out);
    povfile<<povray_templates::header;
    povfile<<povray_templates::coords;

    /*test_cut(povfile,Vec3(0,0,1));
    test_cut(povfile,Vec3(0,0,-1));
    test_cut(povfile,Vec3(0,1,0));
    test_cut(povfile,Vec3(0,-1,0));
    test_cut(povfile,Vec3(1,1,0));
    test_cut(povfile,Vec3(-1,-1,0));*/

    for(int i=0;i<720;++i)
    {
        test_cut(povfile,Vec3(cos(2*M_PI*i/360),sin(2*M_PI*i/360),0));
        test_cut(povfile,Vec3(0,cos(2*M_PI*i/360),sin(2*M_PI*i/360)));
    }

    povfile.close();

    povray_templates::make_base(filebase,100,1);
}

void test_rotation(const char* filebase)
{
    char fname[256];
    memset(fname,0,sizeof(fname));
    strcat(fname,filebase);
    strcat(fname,".pov");
    ofstream povfile;
    povfile.open(fname,ofstream::out);
    povfile<<povray_templates::header;
    povfile<<povray_templates::coords;

    int n = 100;
    for(int p = 0; p < n; ++p) {
      double z = -1 + 2. * p / n;
      for(int q = 0; q < n; ++q) {
	double phi = 2 * M_PI * q / n;
	double r = sqrt(1 - z*z);
	Vec3 v(r*cos(phi), r*sin(phi),z);
	try {
	  test_cut(povfile, v);
	} catch(string msg) {
	  cerr << "problem: " << msg << " p = " << p << " q = " << q << endl;
	}
      }
    }

    povfile.close();
}

int main()
{
  try {
    test_cuts("povray");
  } catch(string msg) {
    cerr << "error: " << msg << endl;
  }
    return 0;
}
