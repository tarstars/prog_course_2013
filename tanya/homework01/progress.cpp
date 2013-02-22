#include <iostream>
using namespace std;
int main()
{
  int b0,q,bn;
  for( b0=1,q=2,bn=b0*q;bn<2000;b0=bn,bn=b0*q)
  {
    cout<<b0<<" ";
  }
}

