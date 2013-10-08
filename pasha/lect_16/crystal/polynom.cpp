#include<iostream>
#include"polynom.h"
#include<cmath>

using namespace std;

double
Polynom::at(int n) const {
    if(n==0) return z;
    else if(n==1) return y;
    else if(n==2) return x;
    else if(n==3) return w;
    else return 0;
}

ostream& operator<<(ostream& os,const Polynom& Pol){
    return os << Pol.w << " " << Pol.x << " " << Pol.y << " " << Pol.z;
}

double*  
Polynom::solvePolynom() { // Solve cubic equation in case of real roots;
    double *root;
    root = new double[3];
    double Q, R;
    double a, b, c;
    double pi = 3.141592653589793;
    double eps = 0.0000000001;
    a = x/w;
    b = y/w;
    c = z/w;
    Q = (a*a - 3.*b)/9.;
    R = (2.*a*a*a - 9.*a*b + 27.*c)/54.;
    //cout<<Q*Q*Q - R*R<<endl;
    if(Q*Q*Q - R*R > 0) {
        double t = acos(R/sqrt(Q*Q*Q))/3.;
        root[0] =  -2.*sqrt(Q)*cos(t) - a/3.;
        root[1] =  -2.*sqrt(Q)*cos(t+2.*pi/3.) - a/3.;
        root[2] =  -2.*sqrt(Q)*cos(t - 2.*pi/3.) - a/3.;
    }
    else if(abs(Q*Q*Q - R*R)<eps) {
        root[0]= -2.0*cbrt(R) - a/3.;
        root[1] = cbrt(R)-a/3.;
        root[2] = root[1];
    }
    else {
        cerr<<"Not all roots real, return 0"<<endl;
        root[0] = 0;
        root[1] = 0;
        root[2] = 0;
    }
    return root;
}
