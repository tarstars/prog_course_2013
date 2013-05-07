#include <iostream>
#include <map>

using namespace std;

map<int, int> freq, vals;

int f(int n) {
  ++freq[n]; 

  if (vals.find(n) != vals.end())
    return vals[n];

  if (n < 2) {
    vals[n] = 1;
    return 1;
  }

  vals[n] = f(n - 1) + f(n - 2);
  return vals[n];
}

int main() {
  int t = f(8);
  cout << endl;
  cout << t << endl;
  for(map<int, int>::iterator it = freq.begin(); it != freq.end(); ++it) {
    cout << it -> first << " -> " << it -> second << endl;
  }

  return 0;
}
