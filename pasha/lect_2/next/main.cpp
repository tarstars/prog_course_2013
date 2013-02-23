#include <iostream>
using namespace std;
bool next(int *pa, int *pb){
  int j=pb-pa;
  while((((pa[j-1]==0)&&(pa[j]==1))!=1)&&(j>=1)){
    j--;
  }
  if(j==0){
    return false;
  }
  else{
    pa[j-1]=1; pa[j]=0;
    return true;
  }
}

int main() {
  int a[]={1,1,1,1,1};
  int l=sizeof(a)/sizeof(int);
  int exit=0, b[l];
  for(int i=0; i<=l-1; i++){
    b[i]=a[i];
    cout<<a[i];
    if(a[i]!=1){
      if(a[i]!=0){
	exit++;
      }
    }
  }
  if(exit!=0){
    cout<<"\n"<<"ОШИБКА!!! Число должно состоять из нулей и единиц!";
  }
  else{
    cout<<" -> ";
    int *pa=a;
    int *pb=a+l-1;
    bool boo=next(pa,pb);
    if(boo==true){
      for(int i=0; i<=l-1; i++){
	cout<<a[i];
      }
    }
    else{
      for(int i=0; i<=l-1; i++){
	cout<<b[i];
      }
      cout<<"\n"<<"Операция next не может быть больше проведена!";
    }
  }
    cout<<"\n";
    return 0;
}
