// Hanoi Tower emulator. 
// N - number of discs, 3 Spindeln, 
// x - source Spindel, z - destination Spindel
// 1 turn -> show result of this turn

#include <iostream>
#include <list>
#include <vector>

using namespace std;

template<typename T>
ostream& print(ostream& os, T itb, T ite) {
  for(; itb != ite; ++itb) {
    os << *itb << " ";
  }
  return os;
}

void Print(vector<list<char> > dat) {
  print(cout, dat[0].begin(), dat[0].end() ) << endl;
  print(cout, dat[1].begin(), dat[1].end() ) << endl;
  print(cout, dat[2].begin(), dat[2].end() ) << endl;
}

int GetInt(void) {
  int z;
  while( true ) {
    cin >> z;
    if( z != 1 && z != 2 && z != 3 ) { 
      cout << "Wrong x, retry..." << endl; 
      continue; 
    }
    else break;    
  }
  return z;
}

int main() {
  vector<list<char> > dat(3);
  int N, x, z;

  cout << "Enter a number of discs N, N >= 0 : " << endl;  
  while( true ) {
    cin >> N;
    if( !( N >= 0) ) { cout << "Wrong N, retry..." << endl; continue; }
    else break;    
  }
  cout << "Choose spindel (1, 2, 3) : \n";
  x = GetInt();
  for(int i=0; i < N; i++) 
    dat[x-1].push_back('a' + i);

  Print(dat);

  while( true ) {  
    cout << "Choose source spindel (1, 2 or 3): \n"; 
    cout << "(Enter 0 to exit)." << endl;

    while( true ) {
      cin >> x;
      if( x != 0 && x != 1 && x != 2 && x != 3 ) { 
	cout << "Wrong x, retry..." << endl; 
	continue; 
      }
      else break;    
    }
    if ( x == 0 ) break;

    cout << "Choose destination spindel: \n";
    z = GetInt();
    dat[z-1].push_back(dat[x-1].back());
    dat[x-1].pop_back();

    Print(dat);
  }
  return 0;
}
