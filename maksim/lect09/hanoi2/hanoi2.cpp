// Hanoi Tower emulator. 
// N - number of discs, 3 Spindeln, 
// x - source Spindel, z - destination Spindel

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

void HanoiTower(vector<list<char> >& dat,int alpha, int beta, int n)
{
  static int i = 0;
  if( n == 1 ) { 
    ++i;
    cout << "Turn " << i << " : " << endl;
    dat[beta-1].push_back(dat[alpha-1].back()); 
    dat[alpha-1].pop_back(); 
    Print(dat); 
  }
  else {
    HanoiTower(dat, alpha, 6 - alpha - beta, n - 1 );
    HanoiTower(dat,  alpha, beta, 1);
    HanoiTower(dat, 6 - alpha - beta, beta, n - 1 );
  }
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
  cout << "Choose initial spindel (1, 2, 3) : \n";
  x = GetInt();
  for(int i=0; i < N; i++) 
    dat[x-1].push_back('a' + i);
  cout << "Choose destination: \n";
  z = GetInt();
  Print(dat);

  HanoiTower(dat, x, z, N);

  return 0;
}
