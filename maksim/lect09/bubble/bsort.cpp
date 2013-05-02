#include <iostream>
#include <stdlib.h>
#include "tmplts.h"

using namespace std;

int main() {
  int x;
  list<int> List;
  vector<int> Array;

  const int N = 100;
  for(int i = 0; i < N; i++) {
    x = rand();
    List.push_back(x);
    Array.push_back(x);
  } 
  cout << "VECTOR and LIST: \n";
  print(Array.begin(), Array.end());

  bubble_sort(Array.begin(), Array.end());
  bubble_sort(List.begin(), List.end());

  cout << "after sort():\n";
  cout << "\nARRAY :\n";
  print(Array.begin(), Array.end());

  cout << "\nLIST :\n";
  print(List.begin(), List.end());
  
  return 0;
}
