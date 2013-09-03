#include <iostream>
#include <map>
#include <utility>

using namespace std;

map<pair<int,int>, int> vals, freq, freq1;

int C_nomem(int n, int k) {
  pair<int, int> z(n, k);
  ++freq1[z];
  
  if( k == 0 || k == n ) {
    return 1; 
  }
  else {
    return C_nomem( n - 1, k - 1) + C_nomem( n - 1, k );
  }
}

int C_n_k(int n, int k) {
  pair<int, int> z(n, k);
  ++freq[z];
  
  if(vals.find(z) != vals.end()) 
    return vals[z];

  if( k == 0 || k == n ) { 
    vals[z] = 1; 
    return 1; 
  }
  else {
    vals[z] = C_n_k( n - 1, k - 1) + C_n_k( n - 1, k );
    return vals[z];
  }
}



int main() {
  cout << "\nBefore memoization : \n";

  int x = C_nomem(7, 3);
  cout << endl;
  cout << "C(7,3) = " << x << endl;
  for(map<pair<int, int>, int>::iterator it = freq1.begin(); it != freq1.end(); ++it) {
    cout << "(" << it -> first.first << "," << it->first.second  << ") " << " -> " << it -> second << endl;
  }
  cout << "\nAfter memoization :\n"; 

  int t = C_n_k(7, 3);
  cout << endl;
  cout << "C(7,3) = " << t << endl;
  for(map<pair<int, int>, int>::iterator it = freq.begin(); it != freq.end(); ++it) {
    cout << "(" << it -> first.first << "," << it->first.second  << ") " << " -> " << it -> second << endl;
  }
  
  return 0;
}
