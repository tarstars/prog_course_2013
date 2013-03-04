#include <iostream>
#include <math.h>

using namespace std;
//значение многочлена и его производной
//на входе: x a_0 ... a_n

int main() {
  int n=-1;
  double x,a, mnog=0,prois=0;
  while(cin>>a){
    if(n==-1){
      x=a;
    }
    else{
      mnog+=a*pow(x,n);
      prois+=a*n*pow(x,n-1);
    }
    ++n;
  }
  cout<<"mnog="<<mnog<<"\n";
  cout<<"prois="<<prois<<"\n";
  return 0;
}
