#include <iostream>
using namespace std;

bool next(int *pb, int *pe){
  int j=pe-pb, n1=0, j1;
  
  for(int i=0; i<=j; ++i) {
    cout<<*(pb+i); //вывод исходного массива
  }
  cout<<" -> ";
  
  while((((pb[j-1]==0) && (pb[j]==1))!=1)  &&  (j>=1)) {
    --j;
    if(pb[j]==1) {
      ++n1; //подсчёт кол-ва 1
      if(n1==1) {
	j1=j; // место первой 1
      }
    }
  }
  if(j==0) {
    cout<<"???\n"<<"Операция next невозможна!"<<endl;
    return false;
  }
  else {
    pb[j-1]=1; pb[j]=0;

    int nost=0;
    for(int k=j-2; k>=0; --k) {
      if(pb[k]==1){++nost;} //подсчёт кол-ва 1 после первого 0
    }
    if((nost==0) & (n1>=1) & (n1<pe-pb-j-1)) {
      for(int i=j1; i>=j+1; --i) {
	pb[i]=0; *(pe-(j1-i))=1; //сдвиг оставшихся 1 в самый младший разряд
      }
    }

    for(int i=0; i<=pe-pb; ++i) {
      cout<<*(pb+i); //вывод результата next
    }
    cout<<endl;
    return true;
  }
}

int main() {
  
  int a[]={0,0,0,1,1,1,1,1,1};
  int l=sizeof(a)/sizeof(int);
  int *pb=a;
  int *pe=a+l-1;
  while(next(pb,pe)){};
  return 0;
}
