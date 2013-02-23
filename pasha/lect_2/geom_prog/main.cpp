#include <iostream>
using namespace std;
// вывести геом прогресию с знаменателем 2, b0=1, до 2000

int main() {
  int b0=1, bmax=2000, q=2;
  int b=b0;
  int i=0;
  while(q*b<bmax){
    b=b*q;
    cout<<"b"<<i<<"="<<b<<"\n";
    i++;
  }
  return 0;
}
