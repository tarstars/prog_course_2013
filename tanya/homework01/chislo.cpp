#include <iostream>
#include <math.h>
using namespace std;
int main(){
  int a,b=0,c,i,j;
 
cout<<"VVedite a:"<< " ";
  cin>>a;
  cout<<endl;
 
  
  for(i=0; a>0; i++)
     {b=a%2;
      a=(a-b)/2;
      c=c+b*pow(10,i);
     }  cout<<c<<endl;
 
}
