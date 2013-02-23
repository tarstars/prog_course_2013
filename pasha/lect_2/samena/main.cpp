#include <iostream>
#include <cstring> 
using namespace std;
//заменить в массиве эл-ты на сумму соседних эл-тов
//(крайние эл-ты не трогать)

int main() {
  int a[]={6,2,15,9,5,1};
  int b[sizeof(a)/sizeof(int)];
  b[0]=a[0];
  b[sizeof(a)/sizeof(int)-1]=a[sizeof(a)/sizeof(int)-1];
  cout<<"Исходный массив:";
  for(int i=0; i<sizeof(a)/sizeof(int); i++){
    cout<<" "<<a[i];
  }
  cout<<"\n";
  cout<<"После суммирования соседних элементов: "<<b[0];
  for(int i=1; i<sizeof(a)/sizeof(int)-1; i++){
    b[i]=a[i-1]+a[i+1];
    cout<<" "<<b[i];
  }
  cout<<" "<<b[sizeof(a)/sizeof(int)-1]<<"\n";
  return 0;
}
