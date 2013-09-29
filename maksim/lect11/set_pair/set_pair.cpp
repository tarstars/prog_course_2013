#include <iostream>
#include <set>
#include <utility>

using namespace std;

void set_print(set<pair<int, int> >& SP) {
  set<pair<int, int> >::const_iterator it = SP.begin();
  set<pair<int, int> >::const_iterator ite = SP.end();
  for(; it != ite; ++it) 
    cout << "(" <<  it -> first << "," << it -> second << ")   ";
  cout << endl;
}

int main() {
  set<pair<int, int> > SP;
  
  for(int i = 0; i <= 5; i++)
    for(int j = 0; j <= 5; j++)
      SP.insert(pair<int,int>(i, j));

  set_print(SP);
  SP.clear();

  cout << endl << "Set filled in other way :" << endl;
  for(int i = 5; i >= 0; i--)
    for(int j = 0; j <= 5; j++)
      SP.insert(pair<int,int>(i, j));

  set_print(SP);   
  return 0;
}
