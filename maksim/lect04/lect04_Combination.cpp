#include <iostream>

using namespace std;

class Combination {
  int n, k; // n - number of '0', k - '1'
  int *pa;
private:
  void shift(int *a, int *b, int *z)
  {
    int *v, *w;
    for( v = z, w = b; w>=a; --v, --w) *v = *w;
    for( ; v >= a ; --v) *v = 0;
  }
public:
  Combination(int _n, int _k) : n(_n), k(_k) {
    pa = new int[ n + k ];
    for(int i = 0; i < n; i++) pa[i] = 0;
    for(int i = n; i < n+k ; i++) pa[i] = 1;
  }
  void print() {
    for(int i = 0; i < n+k ; i++)
      cout << pa[i] ;
    cout << endl;
  }
  bool next() {
    int* begin = pa; int* end = begin + n + k;
    bool flag = true, ismove=false; 
    int *p, *q, *t;
		
    for( p = begin; p != end; ++p) if ( *p == 1 ) break;
    for( q = end - 1; q != begin-1; --q) if( *q == 1) break;			
    if( p==end-1 ) return false;

    for( t=q ; t!=p; t--)
      {
	if( *(t-1)==0 ) 
	  {
	    *(t-1) = 1; *t = 0;
	    if( t+1 <= q ) shift( t+1 , q, end-1 );
	    ismove=true;
	    break;
	  }
      }
    if(ismove == false)
      {
	if( p != begin )
	  {
	    *p = 0; *(p-1) = 1;
	    shift( p+1, q, end-1 );
	  }
	if(p==begin) { flag = false; }
      }
    return flag;
  }
  ostream& operator>> (ostream& os) const {
    for(int i = 0; i < n+k ; i++) os << pa[i];
    return os;
  }
};

ostream& operator<< (ostream& os, const Combination& comb) {
  return comb >> os;
}

int main( ) {
  Combination arr( 2, 2);
  arr.print();
  while(arr.next()) cout << arr << endl;
  
}
