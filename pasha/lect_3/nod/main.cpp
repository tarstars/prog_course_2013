#include <iostream>
#include <math.h>

using namespace std;
//наибольший общий делитель
//a, b, a%b, b%(a%b), ..., nod, 0

int main() {
  int a,b;
  cin>>a>>b;
  while((a!=0)&(b!=0)){
    if(a>b){
      a=a%b; //большее число не нужно => перезапись
    }
    else{
      b=b%a;
    }
  }
  cout<<"nod="<<a+b<<"\n"; //т.к. одно из них равно нулю
  return 0;
}
