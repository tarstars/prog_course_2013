#include <iostream>
#include <math.h>

using namespace std;
//кол-во эл-тов, сумма, среднее, дисперсия

int main() {
  double x,N=0,sum=0,mean=0,sumx2,disp=0;
  while(cin>>x){
    ++N;
    sum+=x;
    sumx2+=pow(x,2);
  }
  mean=sum/N;
  disp=sumx2/N - pow(mean,2);
  cout<<"N="<<N<<"\n";
  cout<<"sum="<<sum<<"\n";
  cout<<"mean="<<mean<<"\n";
  cout<<"disp="<<disp<<"\n";
  return 0;
}
