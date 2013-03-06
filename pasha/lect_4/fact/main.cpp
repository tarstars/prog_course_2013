#include <iostream>
using namespace std;

int fact(int a){
  if(a==0||a==1){
    return 1;
  }
  return a*fact(a-1);
}

int main() {
  int a;
  cout<<"Введите число:\t";
  cin>>a;
  cout<<"Факториал:\t"<<a<<"!="<<fact(a)<<endl;
  return 0;
}

