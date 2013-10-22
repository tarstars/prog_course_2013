#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

ostream& operator<<(ostream& os, const vector<int>& r) {
  /*for(//vector<int>::const_iterator
      auto it = r.begin();
      it != r.end();
      ++it) {
    os << *it << " ";
    }*/

  for(int t : r) {
    cout << t << " ";
  }
  return os;
}

void f(int x) {
  cout << "ku " << x << " times" << endl;
}

int g(int x) { return x * x; }

int main() {
  vector<int> dat = {{1, 2, 5, 7}};
  int cdat[] = {5, 4, 20};
  /*dat.push_back(1);
  dat.push_back(3);
  dat.push_back(5);
  dat.push_back(7);*/

  //cout << dat << endl;

  for_each(begin(dat), end(dat), f);
  cout << "c" << endl;
  for_each(begin(cdat), end(cdat), f);

  cout << "square" << endl;
  int times = 5;

  function<int (int)> pred = [=](int x) {return times*x;};

  transform(begin(dat), end(dat), begin(dat), pred);
  cout << dat << endl;
  return 1;
}
