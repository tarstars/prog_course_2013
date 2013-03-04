#include <iostream>
using namespace std;
 
/*void print1(int *x,int s){
  for(int i = 0; i < s; ++i) {
 cout << *x << " ";
    ++*x;
  }
}

void print2(int *x,int *y){
 while(*x < *y){
    cout << *(x++) << " "; 
 }
}*/

int main()
{
   const int n = 5;
   const int k = 7;
   int a[n+k];
   int t;
   int *pa;
   int *pb;
   int *pe;
   t=n+k;       
   pa=a;
   pb=a;
   pe=pb+n+k;
for(int i = 0; i < n+k; i++)

    { if(i < n)
	a[i] = 0;
      else
	a[i]=1;
      cout << a[i] <<" ";
      
    
  }
   cout << endl; 
   
cout << "print1:" << endl;
 
 for(int i = 0; i < t; ++i) {
   cout << *pa << " ";
   ++pa;
} 
 cout << endl;
 cout << "print2:" << endl;
 
while(pb < pe){
    cout << *(pb++) << " "; 
 }

// cout << "print2:" << endl;
 //print2(pb,pe);
   cout << endl;
 
}

