#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

bool is_good(int t) {return t % 2 == 1;}

int main() {
  vector<int> dat;
  for(int t = 0; t < 20; ++t) {
    dat.push_back(t);
  }

  copy_if(dat.begin(), dat.end(), ostream_iterator<int>(cout, ", "), is_good);
  cout << endl;

  return 0;
}
