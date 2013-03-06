#include <iostream>
using namespace std;

int C(int n, int k) {
  if(n==0 || n==k) {
    return 1;
  }
  return C(n-1,k-1) + C(n,k-1);
}

int main() {
  int n,k;
  cout<<"Биномиальные коэффициенты C(n,k)\n";
  cout<<"Введите n и k: ";
  cin>>n>>k;
  cout<<"C("<<n<<","<<k<<")="<<C(n,k)<<endl;
  return 0;
}

