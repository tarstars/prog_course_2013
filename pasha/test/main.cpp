#include <iostream>
using namespace std;
int main() {
  int i;
  for(i=6; i<10; i=i+1){
    if(i==6){
      cout<<i<<" ";
    }
    else if(i==7){
      cout<<i+10<<" ";
    }
    else{
      cout<<i<<" ";
    }
  }
  return 0;
}
