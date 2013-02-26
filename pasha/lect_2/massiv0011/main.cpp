#include <iostream>
using namespace std;
//заполнить массив из n+k элементов n единичками и k ноликами

int main() {
  const int n=5, k=3;
  int a[n+k];
  for (int i=0; i<=n+k-1;i++){
    if(i<n){
      a[i]=0;
      cout<<"a["<<i<<"]="<<a[i]<<"\n";
    }
    else{
      a[i]=1;
      cout<<"a["<<i<<"]="<<a[i]<<"\n";
    }   
  }
  return 0;
}
