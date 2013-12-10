#include "vec3.h"
#include "Tensor4.h"
#include "matrix.h"
#include "solpart.h"
#include "util.h"
#include "povray_templates.h"

#include <cmath>
#include <vector>

#include <stdlib.h>

using namespace std;

static const vector<PovrayColor> cutColors = {{PovrayColor(0,0,255),
                                               PovrayColor(0,255,0),
                                               PovrayColor(255,0,0)}};
static const PovrayColor polColor("#C29C12");

enum TestCutsMode
{
    TestCuts_Dot,
    TestCuts_Pol,
    TestCuts_DotPol
};

///////////////////////povray test plane cut////////////////////
void test_cut(ostream& os, const Vec3& vec, TestCutsMode mode = TestCuts_Dot)
{
  Vec3 n = vec.normalized();
  Tensor4 tens = makeTetragonalTensor(5.6e10, 5.145e10, 2.2e10, 10.6e10, 2.65e10, 6.6e10);
  double rho = 5.96e3;
  Matrix chrMat = christoffel(tens, n);
  vector<SolPart> sols = solveChristoffel(chrMat,rho);
  qsort(&sols[0],sols.size(),sizeof(SolPart),compareSolPart);

  Vec3 polvec, speed;
  for(size_t l=0;l<sols.size();++l)
    {
      speed.set(0,2000*n.at(0)/sols.at(l).getV());
      speed.set(1,2000*n.at(1)/sols.at(l).getV());
      speed.set(2,2000*n.at(2)/sols.at(l).getV());
      polvec = sols.at(l).getVec().normalized()*(1./10);
      switch(mode)
      {
          case TestCuts_Dot:
              outputPovraySphere(os,speed,cutColors.at(l));
              break;
          case TestCuts_DotPol:
              outputPovraySphere(os,speed,cutColors.at(l));
          case TestCuts_Pol:
              outputPovrayCylinder(os,polvec*-1,polvec,0.01,polColor,&speed);
              break;
      }
    }
}

void test_cut_external(ostream& os,
               Tensor4 const& tens,
               const Vec3& vec)
{
  Vec3 n = vec.normalized();
  double rho = 5.96e3;
  Matrix chrMat = christoffel(tens, n);
  vector<SolPart> sols = solveChristoffel(chrMat,rho);
  qsort(&sols[0],sols.size(),sizeof(SolPart),compareSolPart);

  for(size_t l=0;l<sols.size();++l)
    {
      Vec3 speed(2000*n.at(0)/sols.at(l).getV(),
         2000*n.at(1)/sols.at(l).getV(),
         2000*n.at(2)/sols.at(l).getV());

      outputPovraySphere(os,speed,cutColors.at(l));
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

    int n = 720;
    for(int i=0;i<n;++i)
    {
        test_cut(povfile,Vec3(cos(2*M_PI*i/n),sin(2*M_PI*i/n),0));
        test_cut(povfile,Vec3(0,cos(2*M_PI*i/n),sin(2*M_PI*i/n)));
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

    Tensor4 tens = makeTetragonalTensor(5.6e10, 5.145e10, 2.4e10, 10.6e10, 2.65e10, 6.6e10);
    Matrix rotMat = rotX(0.57);
    cout << tens << endl << endl;
    Tensor4 rtens = tens.tensorRot(rotMat);
    cout << rtens << endl;

    int n = 100;
    for(int p = 0; p < n; ++p) {
      double z = -1 + 2. * p / n;
      for(int q = 0; q < n; ++q) {
    double phi = 2 * M_PI * q / n;
    double r = sqrt(1 - z*z);
    Vec3 v(r*cos(phi), r*sin(phi), z);
    try {
      test_cut_external(povfile, rtens, v);
    } catch(string msg) {
      cerr << "problem: " << msg << " p = " << p << " q = " << q << endl;
    }
      }
    }

    povfile.close();
}
///////////////////////povray test rotation/////////////////////

///////////////////////povray test cut rotation/////////////////
void test_cutrotation(const char* filebase)
{
    char fname[256];
    memset(fname,0,sizeof(fname));
    strcat(fname,filebase);
    strcat(fname,".pov");
    ofstream povfile;
    povfile.open(fname,ofstream::out);
    povfile<<povray_templates::statheader;
    povfile<<povray_templates::coords;

    int n = 100, an = 360;
    for(int p = 0; p < n; ++p)
    {
        Vec3 norm(sin(2*M_PI*p/n),0,cos(2*M_PI*p/n));
        Matrix rot(3,3);
        double dTheta=2*M_PI/an;
        rot.Set(0,0,cos(dTheta)+norm.at(0)*norm.at(0)*(1-cos(dTheta)));
        rot.Set(0,1,norm.at(0)*norm.at(1)*(1-cos(dTheta))-norm.at(2)*sin(dTheta));
        rot.Set(0,2,norm.at(0)*norm.at(2)*(1-cos(dTheta))+norm.at(1)*sin(dTheta));
        rot.Set(1,0,norm.at(0)*norm.at(1)*(1-cos(dTheta))+norm.at(2)*sin(dTheta));
        rot.Set(1,1,cos(dTheta)+norm.at(1)*norm.at(1)*(1-cos(dTheta)));
        rot.Set(1,2,norm.at(1)*norm.at(2)*(1-cos(dTheta))-norm.at(0)*sin(dTheta));
        rot.Set(2,0,norm.at(0)*norm.at(2)*(1-cos(dTheta))-norm.at(1)*sin(dTheta));
        rot.Set(2,1,norm.at(1)*norm.at(2)*(1-cos(dTheta))+norm.at(0)*sin(dTheta));
        rot.Set(2,2,cos(dTheta)+norm.at(2)*norm.at(2)*(1-cos(dTheta)));
        povfile<<"#if (clock = "<<p<<")\n";
        Vec3 v(0,1,0);
        for(int i = 0;i<an;++i)
        {
            try
            {
                test_cut(povfile, v);
            }
            catch(string msg)
            {
                cerr << "problem: " << msg << " p = " << p <<" vec "<< v << endl;
            }
            v = rot*v;
        }
        povfile<<"#end\n\n";
    }

    povfile.close();

    povray_templates::make_base(filebase,n,(n-1));
}
///////////////////////povray test cut rotation/////////////////

///////////////////////povray test cut rotation/////////////////
void test_cutrotationpol(const char* filebase)
{
    char fname[256];
    memset(fname,0,sizeof(fname));
    strcat(fname,filebase);
    strcat(fname,".pov");
    ofstream povfile;
    povfile.open(fname,ofstream::out);
    povfile<<povray_templates::statheader;
    povfile<<povray_templates::coords;

    int n = 100, an = 360;
    for(int p = 0; p < n; ++p)
    {
        Vec3 norm(sin(2*M_PI*p/n),0,cos(2*M_PI*p/n));
        Matrix rot(3,3);
        double dTheta=2*M_PI/an;
        rot.Set(0,0,cos(dTheta)+norm.at(0)*norm.at(0)*(1-cos(dTheta)));
        rot.Set(0,1,norm.at(0)*norm.at(1)*(1-cos(dTheta))-norm.at(2)*sin(dTheta));
        rot.Set(0,2,norm.at(0)*norm.at(2)*(1-cos(dTheta))+norm.at(1)*sin(dTheta));
        rot.Set(1,0,norm.at(0)*norm.at(1)*(1-cos(dTheta))+norm.at(2)*sin(dTheta));
        rot.Set(1,1,cos(dTheta)+norm.at(1)*norm.at(1)*(1-cos(dTheta)));
        rot.Set(1,2,norm.at(1)*norm.at(2)*(1-cos(dTheta))-norm.at(0)*sin(dTheta));
        rot.Set(2,0,norm.at(0)*norm.at(2)*(1-cos(dTheta))-norm.at(1)*sin(dTheta));
        rot.Set(2,1,norm.at(1)*norm.at(2)*(1-cos(dTheta))+norm.at(0)*sin(dTheta));
        rot.Set(2,2,cos(dTheta)+norm.at(2)*norm.at(2)*(1-cos(dTheta)));
        povfile<<"#if (clock = "<<p<<")\n";
        Vec3 v(0,1,0);
        for(int i = 0;i<an;++i)
        {
            try
            {
                test_cut(povfile, v,TestCuts_Pol);
            }
            catch(string msg)
            {
                cerr << "problem: " << msg << " p = " << p <<" vec "<< v << endl;

            }
            v = rot*v;
        }
        povfile<<"#end\n\n";
    }

    povfile.close();

    povray_templates::make_base(filebase,n,(n-1));
}
///////////////////////povray test cut rotation/////////////////

int main()
{
  try {
    //test_cuts("povray");
    test_rotation("test_rotation");
    // test_cutrotationpol("cutropol");
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

//Паша: Брезенхейм для окружности
//Андрей:
//Настя: попробовать повернуть картинку
//Дима: нарисовать поляризации
//Таня: дописать бейсик с рэгекспами, чтобы рисовал линии
//
