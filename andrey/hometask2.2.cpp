#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

int main(int argc, char* argv[]) {
  if (argc < 2) {
    cerr << "error, no input file" << endl;
    return 1;
  }
  
  ifstream larg(argv[1]);
  int i = 0;
  double value = 0,x0,x;
  double derivative = 0;
  //////straight order/////////////
  while((larg >> x)) {
    if(i==0){x0=x;}
    else
       {
      value = value + x*pow(x0,i-1);
      derivative = derivative + x*(i-1)*pow(x0,i-2);
       } 
    i  = i + 1;
  }
 /////reverse order////
// while((larg >> x)) {
//     if(i==0){x0=x;}
//     else
//        {
// 	 value = value + x*pow(x0,-(i-1));
// 	 derivative = derivative - x*(i-1)*pow(x0,-(i));
//        } 
//     i  = i + 1;
//   }
//   cout<<i;
//   value = value*pow(x0,i-2);
// derivative = derivative*pow(x0,i-2) + (i-2)*value*pow(x0,-1);
 
  cout<<" value "<<value;
  cout<<" derivative "<<derivative; 
  return 0;
}
