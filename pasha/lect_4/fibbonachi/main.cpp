#include <iostream>
using namespace std;
int fibb(int n){
  if(n==2){
    return 1;
  }
  if(n==1){
    return 0;
  }
  return fibb(n-1)+fibb(n-2);
}
int main() {
  int n,f;
  cout<<"Последовательность Фиббоначи: f(1)=0,f(2)=1,\n";
  cout<<"Введите номер числа (n>=1): ";
  cin>>n;
  cout<<"f("<<n<<")="<<fibb(n)<<endl;
  return 0;
}

