#include <iostream>
#include <math.h>

using namespace std;
//значение многочлена и его производной
//на входе: x a_n ... a_0

int main() {
  int k=3, n=k; //k - пробная степень плюс один
  double x1,x2,x3,dx=exp(-20),a; //dx->0 - для расчёта производной
  double mnog1=0, mnog2=0, mnog3=0, prois;
  while(cin>>a){
    if(n==k){
      x2=a;
      x1=x2-dx;
      x3=x2+dx;
    }
    else{
      mnog1+=a*pow(x1,n);
      mnog2+=a*pow(x2,n);
      mnog3+=a*pow(x3,n);
    }
    --n;
  }
  
  if(n<-1){
    mnog1*=pow(x1,-n-1); //-1 - т.к. сделали лишний шаг
    mnog2*=pow(x2,-n-1);
    mnog3*=pow(x3,-n-1);
  }
  
  prois=(mnog3-mnog1)/2/dx; //пока только численно :(

  cout<<"mnog="<<mnog2<<"\n";
  cout<<"prois="<<prois<<"\n";
  
  return 0;
}
