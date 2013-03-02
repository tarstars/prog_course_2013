#include <iostream>
#include <math.h>

using namespace std;
//значение многочлена и его производной
//на входе: x a_n ... a_0

int main() {
  int n=-1;
  double x,a2,a1;
  double mnog=0;
  double prois1, prois2, prois;
  while(cin>>a2){
    if(n==-1){
      x=a2;
    }
    else{
      mnog=mnog*x+a2;
      if(n==0){
	prois1=0;
	prois2=0;
      }
      if(n==1){
	prois2=a1;
      }
      else{
	prois=(prois2+(prois2-prois1*x))*x+a1;
	prois1=prois2;
	prois2=prois;
      }
      a1=a2; //предыдущее значение a
    }
    ++n;
  }
  cout<<"Степень многочлена: "<<n-1<<"\n";
  cout<<"mnog="<<mnog<<"\n";
  cout<<"prois="<<prois<<"\n";
  
  return 0;
}
