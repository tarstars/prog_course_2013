#include<iostream>
using namespace std;

int main() {
  cout<<"Введите a и b: "<<endl;
  cin>>a>>b;
#ifdef plus
  cout<<"a+b="<<a+b<<endl;
#endif
#ifdef minus
  cout<<"a-b="<<a-b<<endl;
#endif
#ifdef product
  cout<<"a*b="<<a*b<<endl;
#endif
#ifdef division
  cout<<"a/b="<<a/b<<endl;
#endif
}
