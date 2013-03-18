#include <iostream>
#include <ostream>
using namespace std;

class combination {
  int N0,N1; //кол-во нулей и единиц
  int *pb;
public:

  combination(int N00, int N11): N0(N00), N1(N11) {
    pb = new int[N0+N1];
    for (int i=0; i<N0+N1; ++i) {
      if(i<N0) { pb[i]=0;}
      else     { pb[i]=1;}
    }
  }

  ostream& print(ostream& os)  {
    for(int i=0; i<N0+N1; ++i){
      os<<pb[i];
    }
    return os;
  }

  bool next(){
    int j=N0+N1-1, n1=0, j1;
    int *pe=pb+j;
  
    while((((pb[j-1]==0) && (pb[j]==1))!=1)  &&  (j>=1)) {
      --j;
      if(pb[j]==1) {
	++n1; //подсчёт кол-ва 1
	if(n1==1) {
	  j1=j; // место первой 1
	}
      }
    }
    if(j==0) {
      cout<<"???\n"<<"Операция next невозможна!"<<endl;
      return false;
    }
    else {
      pb[j-1]=1; pb[j]=0;
    
      int nost=0;
      for(int k=j-2; k>=0; --k) {
	if(pb[k]==1){++nost;}
      }
      if((nost==0) & (n1>=1) & (n1<pe-pb-j-1)) {
	for(int i=j1; i>=j+1; --i) {
	  pb[i]=0; *(pe-(j1-i))=1; //сдвиг оставшихся 1 в самый младший разряд
	}
      }
      return true;
    }
  }

  ~combination() {
    delete []pb;
  }
};

int main() {
  combination a(2,3);
  while(a.next()) {
    a.print(cout)<<" -> ";
  }
  return 0;
}

