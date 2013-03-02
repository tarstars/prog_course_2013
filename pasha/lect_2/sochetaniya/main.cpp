#include <iostream>
#include <math.h>
using namespace std;
//________________________________________
int num2bin(int a){
  int max=0,n=0,d;
  if(a==0){
    cout<<"Двоичное представление: 0";
  }
  else{
    while(2*max<=a){
      max=pow(2,n);
      n=n+1;
    }
    cout<<"Двоичное представление: 1";
    int N=n-1; //т.к. сделали лишний шаг
    for(int i=N-1; i>=0; i=i-1){
      //N-1 - т.к. max<->1
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
//________________________________________
//заполнение массива n нулями и k единицами
int create_array(int *pa, int n, int k){
  for (int *pa1=pa; pa1<pa+n+k;++pa1){
    if(pa1<pa+n){
      *pa1=0;
    }
    else{
      *pa1=1;
    }
  }
  return 0;
}
//________________________________________
//распечатка массива
int print(int *pa,int sz){
    for(int i=0; i<sz; i++, pa++){
      cout<<" "<<*pa;
    }
    cout<<"\n";
    return 0;
  }
//________________________________________
//следующее значение в двоичной системе
//число единиц и нулей постоянно
bool next(int *pb, int *pe){
  int j=pe-pb;
  while((((pb[j-1]==0)&&(pb[j]==1))!=1)&&(j>=1)){
    j--;
  }
  if(j==0){
    return false;
  }
  else{
    pb[j-1]=1; pb[j]=0;
    return true;
  }
}
//________________________________________
//сдвинуть эл-ты массива на sh позиций
//(по кругу)
int shift(int *a, int sz, int sh){
  int b[sz];
  while(sh>=sz-1){
    sh=sh-(sz-1)-1;
  }
  for(int i=0;i<sz;i++){
    if((i+sh)<sz){
      b[i+sh]=a[i];
    }
    else{
      b[sh-(sz-1-i)-1]=a[i];
    }
  }
  for(int i=0;i<sz;i++){
    a[i]=b[i];
  }
  return 0;
}
//________________________________________
//заменить в массиве эл-ты на
//сумму соседних эл-тов
int samena(int *a, int sz){
  int b[sz];
  b[0]=a[0]; //крайние эл-ты не трогать
  b[sz-1]=a[sz-1];
  for(int i=1; i<sz-1; i++){
    b[i]=a[i-1]+a[i+1];
  }
  for(int i=1; i<sz-1; i++){
    a[i]=b[i];
  }
  return 0;
}
//________________________________________
int main() {
  int n=4,k=3,a[n+k],sh=2;
  int num=5;

  num2bin(num);
  
  create_array(a,n,k);

  int sz=sizeof(a)/sizeof(int);
  cout<<"Исходный массив:";
  print(a,sz);

  int *pe=a+sz-1;
  next(a,pe);
  cout<<"Применение next:";
  print(a,sz);

  shift(a,sz,sh);
  cout<<"Cдвиг на sh="<<sh<<" элементов:";
  print(a,sz);
  
  samena(a,sz);
  cout<<"Замена на сумму соседних элементов:";
  print(a,sz);
  
  return 0;
}
