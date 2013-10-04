#include "matrix.h"
#include "util.h"
#include "Tensor4.h"
#include "vec3.h"

Tensor4 makeTetragonalTensor(double c11, double c12, double c13, double c33, double c44, double c66) {
    Tensor4 new_tens;

    double tens2[36];
    for(int t = 0; t < 36; t++) {
      tens2[t] = 0;
    }

    tens2[0] = c11;  tens2[1] = c12;  tens2[2] = c13;
    tens2[6] = c12;  tens2[7] = c11;  tens2[8] = c13;
    tens2[12] = c13; tens2[13] = c13; tens2[14] = c33;
    tens2[21] = c44; tens2[28] = c44; tens2[35] = c66;

    int a=0, b = 0;
    int i = 0, j = 0, k = 0, l = 0;
    for(int n=0; n<36; ++n) {

        if((n%6 == 0) && n!=0) a+=1;
        b = n - 6*a;

        if(a==0 || a==1 || a==2) i=a, j=a;
        if(a==3) i=1, j=2;
        if(a==4) i=0, j=2;
        if(a==5) i=0, j=1;

        if(b==0 || b==1 || b==2) k=b, l=b;
        if(b==3) k=1, l=2;
        if(b==4) k=0, l=2;
        if(b==5) k=0, l=1;

	double v = tens2[b+6*a];
        new_tens.set(i,j,k,l,v);
	new_tens.set(j,i,k,l,v);
	new_tens.set(i,j,l,k,v);
	new_tens.set(j,i,l,k,v);
	new_tens.set(k,l,i,j,v);
	new_tens.set(l,k,i,j,v);
	new_tens.set(l,k,j,i,v);
	new_tens.set(k,l,j,i,v);
    }
    return new_tens;
}

Matrix christoffel(const Tensor4& tens4, const Vec3& n) {
  Matrix new_matrix(3,3);
  
    //\Gamma_il= c_ijkl * n_j * n_k;
    for(int i=0; i<3; ++i) {
        for(int l=0; l<3; ++l) {
	  double val = 0;
	  for(int j=0; j<3; ++j) {
	    for(int k=0; k<3; ++k) {
	      val += tens4.at(i,j,k,l) * n.at(j) * n.at(k);
	    }
	  }
	  new_matrix.Set(i, l, val);
        }
    }
  
    return new_matrix;
}

