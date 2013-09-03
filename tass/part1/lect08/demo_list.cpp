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

int main() {
  list<char> dat_1, dat_2;
  dat_1.push_back('a' + 0);
  dat_1.push_back('a' + 1);
  dat_1.push_back('a' + 2);

  cout << "dat1, dat2 = " << endl;
  print(cout, dat_1.begin(), dat_1.end()) << endl;
  print(cout, dat_2.begin(), dat_2.end()) << endl;

  dat_2.push_back(dat_1.back());
  dat_1.pop_back();

  cout << "dat1, dat2 = " << endl;
  print(cout, dat_1.begin(), dat_1.end()) << endl;
  print(cout, dat_2.begin(), dat_2.end()) << endl;

  vector<list<char> > dat(3);
  dat[0].push_back('a' + 0);
  dat[0].push_back('a' + 1);
  dat[0].push_back('a' + 2);

  dat[1].push_back(dat[0].back());
  dat[0].pop_back();
  
}
