#include <iostream>

using namespace std;

class OurArray {
  int n;
  double *pDat;
public:
  OurArray(int nn) : n(nn) {
    pDat = new double[n];
  }
  OurArray(const OurArray& r) {
    n = r.n;
    pDat = new double[r.n];
    for(int t = 0; t < r.n; ++t) 
      pDat[t] = r.pDat[t];
  }
  OurArray& operator=(const OurArray& r) {
    if (this == &r) {
      return *this;
    }
    delete [] pDat;
    n = r.n;
    pDat = new double[r.n];
    for(int t = 0; t < r.n; ++t) 
    pDat[t] = r.pDat[t];

    return *this;
  }
  double& at(int ind) {return pDat[ind];}
  ostream& print(ostream& os) const {
    for(int t = 0; t < n; ++t) 
      os << pDat[t] << " ";
    return os;
  }
  ~OurArray() {
    delete []pDat;
  }
};

int main() {
  OurArray x(10);
  x.at(3) = 4;
  OurArray y = x;
  x.print(cout) << endl;
  y.print(cout) << endl;

  OurArray z(10);
  z = x;
}
