#include <iostream>
#include <ostream>
using namespace std;

class OurArray{
  int n;
  double *pDat;
public:
  OurArray(int nn): n(nn) {
    cout<<"\n(конструктор in)  ->  ";
    pDat=new double[n];
    cout<<"(конструктор end)"<<endl;
  }

  OurArray(OurArray const& r) {	//копирующий конструктор
    cout<<"\n(копирующий конструктор in)  ->  ";
    n=r.n;
    pDat=new double[r.n];
    for(int i=0; i<r.n; ++i) {
      pDat[i]=*(r.pDat+i);
    }
    cout<<"  (копирующий конструктор out)"<<endl;
  }

  // OurArray operator=(const OurArray& r) {
  //   cout<<"\n оператор = in  ->  ";
  //   if(n==r.n) {
  //     for(int i=0; i<n; ++i) {
  // 	pDat[i]=*(r.pDat+i);
  //     }
  //   }
  //   else {
  //     cout<<"Присваивание невозможно";
  //   }
  //   cout<<" оператор = out"<<endl;
  // }
  
  double& at(int ind) {
    cout<<"(функция at in)  ";
    return pDat[ind];
  }
	
  ostream& print(ostream& os) const {
    cout<<"\n(функция print in)  ->  ";
    for(int i=0; i<n; ++i) {
      os<<pDat[i]<<" ";
    }
    cout<<"  ->  (функция print out)";
    return os;
  }
	
  ~OurArray() {
    cout<<"\n(деструктор)";
    delete []pDat;
  }
};

int main(){
  OurArray x(3);
  x.at(0)=6; x.at(1)=1; x.at(2)=2;

  OurArray y=x; //вызов копирующего конструктора
  cout<<"x = ";
  x.print(cout);
  cout<<"\ny = ";
  y.print(cout);

  OurArray z(3);
  z=x;	//1)всё работает без оператора =, хотя ничего вроде не менял
        //2)вызвается оператор = (если он есть),
        //  а сразу после него зачем-то вызывается деструктор
        //  но все переменные при этом остаются живы
  cout<<"z = ";
  z.print(cout);
}

