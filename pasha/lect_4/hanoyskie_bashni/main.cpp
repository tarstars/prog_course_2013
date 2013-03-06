#include <iostream>
using namespace std;

int hb(int a, int b, int n) {
  int c=6-a-b; //номер промежуточной башни
  if(n==1){
    cout<<a<<"->"<<b<<endl;
    return 0;
  }
  hb(a,c,n-1);
  hb(a,b,1);
  hb(c,b,n-1);
  return 1;
}

int main() {
  int a,b,n;
  cout<<"Ханойские башни\n";
  cout<<"Номер исходной башни: ";
  cin>>a;
  cout<<"Номер конечной башни: ";
  cin>>b;
  cout<<"Число колец: ";
  cin>>n;
  cout<<"Кольца нужно перекладывать так:\n";
  hb(a,b,n);
  return 0;
}

