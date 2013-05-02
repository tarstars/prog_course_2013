#include <iostream>
#include <list>
#include <string> 

using namespace std;

int main() {
  list<string> lst;
  string s;

  cout << "Enter any words : \n"; 
  while(cin.peek()!='\n') {
    cin >> s;
    lst.push_front(s); 
  }
  cout << "The words in inverse order : \n";
  list<string>::iterator it = lst.begin();
  for( ; it != lst.end() ; ++it) 
    cout << *it << " ";

  cout << endl;
  return 0;
}
