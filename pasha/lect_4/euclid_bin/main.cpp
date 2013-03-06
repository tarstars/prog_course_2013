#include <iostream>
using namespace std;

int nodbin(int m, int n) {

  if((m==0) && (n!=0)) {return n;}
  if((m!=0) && (n==0)) {return m;}
  if(m==n) {return m;}
  if((m==1) && (n!=0)) {return 1;}
  if((m!=0) && (n==1)) {return 1;}

  if((m%2==0) && (n%2==0)) {return 2*nodbin(m/2,n/2);}
  if((m%2==0) && (n%2!=0)) {return nodbin(m/2,n);}
  if((m%2!=0) && (n%2==0)) {return nodbin(m,n/2);}
  if((m%2!=0) && (n%2!=0) && m>n) {return nodbin((m-n),n);}
  if((m%2!=0) && (n%2!=0) && n>m) {return nodbin((n-m),m);}  
}

int main() {
  int a,b;
  cout<<"Бинарный алгоритм Евклида определения НОД\n";
  cout<<"Введите числа a и b: ";
  cin>>a>>b;
  cout<<"НОД("<<a<<","<<b<<")="<<nodbin(a,b)<<endl;
  return 0;
}

