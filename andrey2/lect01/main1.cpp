#include <iostream>
#include <math.h>
using namespace std;

int main(){

  int i, num, num_len, temp;
  
  cout << "Input some numbers:" << endl;
 
  while(cin >> num){
    if(num == 0){
      cout << num << " =  0" << endl;
      continue;
    }
    if(num < 0){
      num = -num;
      cout << "--";
    }
    cout << num << " = ";
    num_len=int(log(num)/log(2))+1;
    for(i=num_len-1; i>=0; --i){
      temp = (num >> i)&1;
      cout << temp;
    }
    cout << endl;
  }

  return 0;
}
