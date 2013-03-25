#include "permutation.h"
#include <algorithm>

using namespace std;

Permutation::Permutation(int n) : Prm(n) {
  for( int i = 0; i < n; i++ ) Prm[i] = i + 1;
}

Permutation::Permutation(const Permutation& r) {
  Prm = r.Prm;
}

void Permutation::rearrange( int i, int j ) {
  int temp = Prm[i];
  Prm[i] = Prm[j];
  Prm[j] = temp;
}

bool Permutation::next() {
  int n = Prm.size();
  for( int i = n-1 ; i>= 1 ; i-- ) {
    if( Prm[i]-Prm[i-1] >= 1 ) {
      for( int k = 1; Prm[i-1]+k <= Prm[i] ; k++ ) {  
	for(int j = n-1 ; j >= i; j--) { 
	  if( Prm[j] == Prm[i-1] + k ) { 
	    rearrange( i-1, j ); 
	    sort( &Prm[i], &Prm[n] ); 
	    return true;
	  }
	}
      }
      rearrange( i-1, i );
      sort( &Prm[i], &Prm[n] );
      return true;
    }
  }
  return false;
}

Permutation& Permutation::operator = (const Permutation& r) {
  Permutation tmp(r);
  tmp.Prm.swap( Prm );
  return *this;
}

Permutation Permutation::operator * (const Permutation& a) {
  int n = Prm.size();
  Permutation res(n);
  for(int i = 0; i < n; i++) res.Prm[i] = Prm[ a.Prm[i] - 1 ];
  return res;
}

ostream& operator << ( ostream& os, const Permutation& perm) {
  os << "( ";
  for(int i = 0; i < perm.Prm.size(); i++ ) os << perm.Prm[i] << " ";
  os << ")";
  return os;
}
