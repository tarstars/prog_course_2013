#include <iostream>
#include <cmath>
using namespace std;

//мнк: y=kx+b
int main() {
  int n=0;
  double x,sumx=0,sumx2=0;
  double y,sumy=0,sumy2=0;
  double k,b, sumxy=0;
  
  cout<<"Введите попарно числа x и y: "<<endl;
  while(cin>>x>>y){
    ++n;
    sumx+=x;
    sumy+=y;
    sumx2+=pow(x,2);
    sumxy+=x*y;
  }
  k = (n*sumxy - sumx*sumy) / (n*sumx2 - pow(sumx,2));
  b = (sumy - k*sumx) / n;
  cout<<"y = "<<k<<"* x"<<" + "<<b<<endl;
  return 0;
}

