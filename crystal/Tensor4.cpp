#include "Tensor4.h"
#include "matrix.h"
using namespace std;

ostream& operator <<(ostream& os, const Tensor4& t) {
	os << scientific;
	os.precision(2);
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			os << t.at(i, j, 0, 0) << ' ' << t.at(i, j, 0, 1) << ' ' << t.at(i, j, 0, 2) << "   ";
		}
		os << endl;
		for(int j = 0; j < 3; j++) {
			os << t.at(i, j, 1, 0) << ' ' << t.at(i, j, 1, 1) << ' ' << t.at(i, j, 1, 2) << "   ";
		}
		os << endl;
		for(int j = 0; j < 3; j++) {
			os << t.at(i, j, 2, 0) << ' ' << t.at(i, j, 2, 1) << ' ' << t.at(i, j, 2, 2) << "   ";
		}
		os << endl << endl;
	}
	return os;
}
void Tensor4::tensorRot(const Matrix& m){
  for(int i=0;i < 2 ; ++i){
    for(int j=0;j < 2 ; ++j){
      for(int k=0;k < 2 ; ++k){
	for(int l=0;l < 2 ; ++l){
	  double svertka;
	  for(int i1=0;i1 < 2 ; ++i1){
	    for(int j1=0;j1 < 2 ; ++j1){
	      for(int k1=0;k1 < 2 ; ++k1){
		for(int l1=0;l1 < 2 ; ++l1){
		  svertka += at(i,j,k,l)*m.Get(i1,i)*m.Get(j1,j)*m.Get(k1,k)*m.Get(l1,l);
		}  
	      }
	    }
	  }
	  set(i,j,k,l,svertka);
	}  
      }
    }
  }
}
