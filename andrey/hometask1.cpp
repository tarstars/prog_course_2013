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
  int count=0;
  bool ret=0;
  for(int i=pb-pa - 1;i>0;i--)
  { 
    if ((pa[i-1]==0) && (pa[i]==1))
      {
        pa[i]=0; 
	pa[i-1]=1;
        ret = true;
	for(int k=1;k<=count;k++)
	  {
	    pa[i+k]=0; 
	  }
	for(int k=1;k<=count;k++)
	  {
	    pa[pb-pa-k]=1; 
	  }	
      }
    else
      {
      
	if(pa[i]==1){count++;}
	ret = false;
      }
    if (ret==true) break;
  }
  return  ret;
}
int shift(int *a,int *b)
{
  int temp=0;
  for(int i=0;i< b - a-1;i++)
    {
      if(i==0)
	{
	  temp = a[1];
	  a[1] = a[0];
	}
      if(i==a - b-2)
	{
	  a[0]=a[i+1];
	  a[i+1]=temp;
	}
      if(i!=0 && i!=a-b-2)
	{
      a[0] = a[i+1];
      a[i+1] = temp;
      temp = a[0];
	}
    }
}
int side_sum_array(int *a, int *b)
{
  int temp0 = 0;
  int temp1 = 0;
  for(int i=1;i< b - a-1;i++)
    {
      if(i==1)
	{
	  temp0 = a[i];
	  a[i] = a[i-1] + a[i+1];
	}
      else
	{
	  temp1 = a[i];
	  a[i] = temp0 + a[i+1];
          temp0 = temp1; 
	}
    }
}
int main()
{
  bool d=true;
  int n,k;
  cout<<"Enter length"<<" ";
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++) 
    {
      cout<<"Enter a["<<i<<"] ";
      cin>>a[i];
     
    }
  //shift(a,a+n);
  side_sum_array(a,a+n);
  print2(a,a+n);
}
 /* cout<<"Enter amount of ones"<<" ";
  cin>>k; 
  int pa[n];
  create_array(pa,n,k);
  print(pa,n);
  cout<<endl;
  while(d)
    {
  d = next(pa,pa+n);
  print2(pa,pa+n);
  cout<<endl; 
    }
  */
