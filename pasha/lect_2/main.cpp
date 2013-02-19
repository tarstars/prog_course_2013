#include <iostream>
using namespace std;
int main() {
  int a=5;
  int b=10;
  int *pa;
  pa=&a;
  int &x=a; //new additional name of variable a
  cout<<"a="<<a<<endl;
  cout<<"x="<<x<<endl;
  cout<<"b="<<b<<endl;
  cout<<"&a="<<&a<<endl; //nomber(adress) of cell in memory of first element of a
  cout<<"pa="<<pa<<endl;
  cout<<"value of variable, which adress lies in pa is"<<*pa<<endl;
}
