#include "vec3.h"
#include "Tensor4.h"
#include "matrix.h"
#include "solpart.h"
#include "util.h"
#include "povray_templates.h"

#include <cmath>
#include <vector>

using namespace std;

///////////////////////povray test plane cut////////////////////
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

        outputPovraySphere(os,speed);
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
///////////////////////povray test plane cut////////////////////

///////////////////////povray test rotation/////////////////////
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
///////////////////////povray test rotation/////////////////////

int main()
{
  try {
    test_cuts("povray");
  } catch(string msg) {
    cerr << "error: " << msg << endl;
  }
    return 0;
}

/*
int main() {
  Tensor4 tens = makeTetragonalTensor(5.6e10, 5.145e10, 2.2e10, 10.6e10, 2.65e10, 6.6e10);
  double rho = 5.96e3;

  for(double phi = 0; phi < 2 * M_PI; phi += 0.01) {
    Vec3 n=Vec3(cos(phi), sin(phi), 0).normalized();
    Matrix chrMat = christoffel(tens, n);
    vector<SolPart> sols = solveChristoffel(chrMat, rho);
    for(size_t p = 0; p < sols.size(); ++p) {
      double s = 1000 / sols[p].getV();
      Vec3 rad = n * s;
      cout << "sphere{<" << rad.at(0) << ", " << rad.at(2) << ", " << rad.at(1) << "> 0.01 pigment { color<0, 0, 1> }}" << endl;
    }
  }

  return 0;
}
*/

//Дима: Сцена 3D - сечения плоскостями (001), (010), (110), с поляризациями
//Паша: полностью отрисованные поверхности медленности шариками, сечение плоскостью. Плоскость поворачивается
//
//
