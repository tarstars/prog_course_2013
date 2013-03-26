#ifndef _PERMUTATION_
#define _PERMUTATION_

#include <iostream>
#include <vector>

class Permutation {
  std::vector<int> Prm;
public: 
  Permutation() {}
  Permutation( int );
  Permutation( const Permutation& );
  void rearrange( int, int );
  bool next();

  Permutation& operator = ( const Permutation& );
  Permutation operator * ( const Permutation& );

  friend std::ostream& operator << ( std::ostream&, const Permutation& );
};

#endif
