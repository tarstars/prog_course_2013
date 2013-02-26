#include <iostream>
#include <math.h>
using namespace std;
//вывести двоичное представление введённого числа

int main() {
  int a,max=0,n=0,d;
  cout<<"Введите число: ";
  cin>>a;
  if(a==0){
    cout<<"Двоичное представление: 0";
  }
  else{
    while(2*max<=a){
      max=pow(2,n);
      n=n+1;
    }
    cout<<"max="<<max<<"\n";
    cout<<"N="<<n-1<<"\n";
    cout<<"Двоичное представление: 1";
    int N=n-1; //т.к. сделали лишний шаг
    for(int i=N-1; i>=0; i=i-1){ //N-1 - т.к. max<->1
      d=a-max;
      if(pow(2,i)<=d){
	cout<<"1";
	max=max+pow(2,i);
      }
      else{
	cout<<"0";
      }
    }
  }
  cout<<"\n";
  return 0;
}
