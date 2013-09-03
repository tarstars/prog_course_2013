#include <iostream>
#include <vector>

using namespace std;

void print(vector<double>& arr) {
  for(int i = 0; i < (int)arr.size(); ++i) {
    cout << arr[i] << " ";
  }
}

void print1(vector<double>::iterator it, int n) {
  for(int i = 0; i < n; ++ i) {
    cout << *it << " "; 
    ++it; 
  }
}

void print2(vector<double>::iterator itb, vector<double>::iterator ite) {
  while(itb < ite) {
    cout << *(itb++) << " ";
  }
}

int main() {
  int n = 4;

  vector<double> dat(n, 314);

  //double *pd = &(dat[5]);

  vector<double>::iterator itb = dat.begin();
  vector<double>::iterator ite = dat.end();

  for(int t = 0; t < n; ++t) {
    dat[t] = t;
  }

  print1(itb, dat.size());
  print2(dat.begin(), dat.end());

  print(dat);

  cout << "1) *itb = " << *itb << endl;
  ++itb;
  cout << "2) *itb = " << *itb << endl;
  itb += 2;
  cout << "3) *itb = " << *itb << endl;

  return 0;
}



