#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

using namespace std;

mutex fmut;

void f(int ind, vector<int>* pdat) {
  vector<int> &dat = *pdat;

  bool todo = true;
  while(todo) {
    {
      lock_guard<mutex> lck(fmut);
      if(dat.size()) {
	cout << ind << " " << dat.back() << endl;
	dat.pop_back();
      } else {
	todo = false;
      }
    }
    
    double s = 0; 
    for(long int t = 0; t < 1e8; t++) {
      s = s + t;
    }
  }
}

int main() {
  vector<int> dat;

  for(int tasks = 0; tasks < 100; tasks++) {
    dat.push_back(tasks);
  }

  const int pn = 10;
  thread pt[pn];

  for(int t = 0; t < pn; ++t) {
    pt[t] = thread(f, t+1, &dat);
  }

  for(int t = 0; t < pn; ++t) {
    pt[t].join();
  }

  return 1;
}
