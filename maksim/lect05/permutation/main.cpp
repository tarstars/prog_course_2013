#include <iostream>
#include "permutation.h"

using namespace std;

int main() {
  Permutation p(4), q(4), r(4);

  cout << "p, q = " << p << endl;
  
  p.rearrange( 1, 3);
  cout << "p.rearrange( 1, 3) : " << p << endl;
  q.rearrange( 1, 2);
  cout << "q.rmearrange( 1, 2) : " << q << endl;

  r = p*q;
  cout << "r = p*q = " << r << endl;

  cout << endl << "next() member function : " << endl;
  Permutation a(5);
  cout << " Permutation a = " << endl;
  
  int i = 1; cout << i << " : "; 
  ++i;
  for( cout << a << endl; a.next(); ++i )    
    cout << i << " : " << a << endl;
    
  return 0;
}
