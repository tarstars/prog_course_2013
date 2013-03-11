#include<iostream>
#include <math.h>
using namespace std;
int create_array(int *pa , int n , int k)
{
  for(int i=0;i<n-k;i++)
  pa[i] = 0;
  for(int i=n-k;i<n;i++)
    pa[i] = 1; 
  return 0;    
}
int print(int *pa, int n)
{
  for(int i=0; i<n;i++)
    cout<<pa[i]<<' ';
    
}
int print2(int *pa, int *pb)
{
  for(int i=0;i<pb-pa;i++)
    cout<<pa[i]<<' ';
}

int binary(int a)
{
  int modpa=0; 
    while(a>0)
    {
      a = floor(a/2);
      modpa = a%2;
      cout<<modpa<<' ';
   
}  
}

bool next(int *pa, int *pb)
{
  bool ret=0;
  for(int i=pb-pa - 1;i>0;i--)
  { 
    if ((pa[i-1]==0) && (pa[i]==1))
      {
        pa[i]=0; 
	pa[i-1]=1;
        ret = true;
		
      }
    else{ ret = false;}
    if (ret==true) break;
  }
  return  ret;
};
int main()
{
  bool d=true;
  int b = 15;
  int pa[10];
  create_array(pa,10,3);
  print(pa,10);
  cout<<endl;
  while(d)
    {
  d = next(pa,pa+10);
  print2(pa,pa+10);
  cout<<endl; 
    }
 
 
  // binary(15);
  //  print(pa,10);
  // print2(pa,pa+10);
 
}
