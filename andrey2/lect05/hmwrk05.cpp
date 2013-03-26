#include <iostream>
#include <utility>
#include <math.h>

using namespace std;

//---------------------------------------------------------

class Vect3 {
  double x, y, z;
public:

  Vect3(double x0, double y0, double z0)
  {
    x = x0;
    y = y0;
    z = z0;
  }

  Vect3()
  {
    x = 0;
    y = 0;
    z = 0;
  }

  Vect3 (const Vect3& r)
  {
    x = r.x;
    y = r.y;
    z = r.z;
 }

  void swap(Vect3& r)
  {
    ::swap(x, r.x);
    ::swap(y, r.y);
    ::swap(z, r.z);
  }

  Vect3& operator=(const Vect3& r)
  {
    Vect3 tmp(r);
    tmp.swap(*this);
    return *this;
  }

  Vect3 operator+(const Vect3& r)
  {
    Vect3 tmp(r);
    tmp.x += x;
    tmp.y += y;    
    tmp.z += z;
    return tmp;
  }

  Vect3 operator*(double coeff)
  {
    Vect3 tmp(*this);
    tmp.x *= coeff;
    tmp.y *= coeff;    
    tmp.z *= coeff;
    return tmp;
  }

  Vect3 operator*(const Vect3& r)
  {
    Vect3 tmp(r);
    tmp.x *= x;
    tmp.y *= y;    
    tmp.z *= z;
    return tmp;
  }

  double& at(int ind)
  {
    switch(ind)
    {
      case 0: return x; break;
      case 1: return y; break;
      case 2: return z; break;
    }
  }

  double length()
  {
    return sqrt(x*x+y*y+z*z);
  }
  
  ostream& print(ostream& os) const
  {
    os << "x = " << x << " y = " << y << " z = " << z << endl;
    return os;
  }

};

//---------------------------------------------------------

class Permutation {
  int n;
  int *pDat;
public:

  Permutation(int nn) : n(nn)
  {
    pDat = new int[n];
    for( int i = 0; i < nn; ++i  )
    {
      pDat[i] = i+1;
    }
  }

  Permutation(const Permutation& r)
  {
    n = r.n;
    pDat = new int[r.n];
    for( int t = 0; t < r.n; ++t )
      pDat[t] = r.pDat[t];
  }

  Permutation& operator=(const Permutation& r)
  {
    Permutation tmp(r);
    tmp.swap(*this);
    return *this;
  }

  void swap(Permutation& r)
  {
    ::swap(n, r.n);
    ::swap(pDat, r.pDat);
  }

  void change(int i1, int i2)
  {
    ::swap(pDat[i1-1], pDat[i2-1]);
  }

  void next()
  {
    int flag = 1;
    int j = n-2;
    while( j!=-1 && pDat[j] >= pDat[j+1] )
      j--;
    if (j == -1)
    {
      flag = 0;
    }
    int k = n - 1;
    while( pDat[j] >= pDat[k] )
      k--;
 
    ::swap(pDat[j],pDat[k]);
 
    int l = j + 1, r = n - 1;
    while( l<r )
      ::swap(pDat[l++],pDat[r--]);
    
    if( flag == 0 )
    {
      Permutation tmp(n);
      tmp.swap(tmp);
    }
  }

  int& at(int ind)
  {
    return pDat[ind];
  }

  Permutation operator*(const Permutation& r)
  {
    Permutation tmp1(n);
    Permutation tmp2 = *this;
    for( int i=0; i<n; ++i )
    {
      tmp1.pDat[i] = tmp2.pDat[r.pDat[i]-1];
    }
    return tmp1;
  }
  
  ostream& print(ostream& os) const
  {
    for( int t = 0; t < n; ++t )
      os << pDat[t];
    return os;
  }

  ~Permutation()
  {
    delete []pDat;
  }

};

//---------------------------------------------------------

int main()
{
  cout << "User's vec3:" << endl;
  Vect3 v1(3, 4, 0);
  v1.print(cout);
  Vect3 v2, v3;
  v2 = v1*2;
  v2.print(cout);
  v3 = v1+v2;
  v3.print(cout);
  v3 = v1*v2;
  v3.print(cout);
  v3.at(2) = 1;
  v3.print(cout);

  cout << endl << "Permutation Class:" << endl;
  Permutation perm1(5);
  Permutation perm2(5);
  Permutation perm3(5);
  perm1.print(cout) << endl;
  perm1.next();
  perm1.print(cout) << endl;
  perm2 = perm1;
  perm2.change(1,2);
  perm2.print(cout) << endl;
  perm3 = perm1*perm2;
  perm3.print(cout) << endl;
}
