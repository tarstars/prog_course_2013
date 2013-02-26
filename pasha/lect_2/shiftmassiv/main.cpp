#include <iostream>
using namespace std;
//сдвинуть эл-ты массива на k позиций (по кругу)

int main() {
  int a[]={1,2,3,4,5,6,7};
  int sz=sizeof(a)/sizeof(int);
  int b[sz];
  int k=14;
  while(k>=sz-1){
    k=k-(sz-1)-1;
  }
  for(int i=0;i<sz;i++){
    if((i+k)<sz){
      b[i+k]=a[i];
    }
    else{
      b[k-(sz-1-i)-1]=a[i];
    }
  }
  cout<<"После k перестановок вправо:";
  for(int i=0;i<sz;i++){
    cout<<" "<<b[i];
  }
  cout<<"\n";
  return 0;
}
