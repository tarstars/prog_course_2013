#include <iostream>
using namespace std;
//распечастка массива print(int *pa, int sz)

int print(int *pa,int sz){
    cout<<"Ваш массив:";
    for(int i=0; i<sz; i++, pa++){
      cout<<" "<<*pa;
    }
    cout<<"\n";
    return 0;
  }
int main() {
  int a[]={1,23,34,465,51,60};
  int *pa=a;
  int sz=sizeof(a)/sizeof(int);
  print(pa,sz);
  return 0;
}
