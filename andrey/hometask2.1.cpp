#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]) {
  if (argc < 2) {
    cerr << "usage: sum  arg1" << endl;
    return 1;
  }
  
  ifstream larg(argv[1]);
  double x=0,sum=0,amount=0, mean=0;
  double sum2  = 0,dispersion=0;
  while((larg >> x)) {
    sum = sum + x;
    amount = amount + 1;
    sum2 = sum2 + x*x;  
  }
  mean = sum/amount;
  dispersion = sum2/amount - mean*mean; 
  cout<<" total "<<sum;
  cout<<" total amount "<<amount;
  cout<<" mean value "<<mean;
  cout<<" Dispersion "<<dispersion;
  return 0;
}

  // ofstream dest(argv[1]);
  // for(int i = 1; i < 2000; i *= 2) {
  //   dest << i << endl;
  // }

