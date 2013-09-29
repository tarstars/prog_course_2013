#include <iostream>

using namespace std;

class Combination {
  int n;
  int k;
  int *pa;
public:
  Combination():n(0),k(0){pa = 0;}
  Combination(int nn, int kk) : n(nn),k(kk) {
    pa = new int[n];
 for(int i=0;i<nn-kk;i++)
    pa[i] = 0;
  for(int i=nn-kk;i<nn;i++)
    pa[i] = 1;
  }
  Combination(const Combination& r) {
    n = r.n;
    pa = new int[r.n];
    for(int t = 0; t < r.n; ++t) 
     pa[t] = r.pa[t];
   }
  ostream& print(ostream& os)const {
    for(int t = 0; t < n; ++t) 
      os << pa[t] << " ";
    return os;
  }
bool next()
{
  int count=0;
  bool ret=0;
  for(int i=n - 1;i>0;i--)
  { 
    if ((pa[i-1]==0) && (pa[i]==1))
      {
        pa[i]=0; 
	pa[i-1]=1;
        ret = true;
	for(int k=1;k<=count;k++)
	  {
	    pa[i+k]=0; 
	  }
	for(int k=1;k<=count;k++)
	  {
	    pa[n-k]=1; 
	  }	
      }
    else
      {
      
	if(pa[i]==1){count++;}
	ret = false;
      }
    if (ret==true) break;
  }
  return  ret;
}
  ~Combination() {
    delete []pa;
  }
};

int main() {
  Combination x(10,5);
  Combination y; y = x;
  x.print(cout) << endl;
  while(y.next()){
  x.print(cout) << endl;
  }
}

