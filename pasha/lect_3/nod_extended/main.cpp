#include <iostream>
#include <math.h>

using namespace std;

//определение наибольшего общего делителя
//с помощью расширенного алгоритма Евклида
//a, b, a%b, b%(a%b), ..., nod, 0  (!)
//и решение в целых числах ур-я: a*x+b*y=nod

//сначала находим попарно все члены ряда (!)
//(a,b) (b,a%b) (a%b,b%(a%b)) ... (nod,0)
//(nod,0)<->(x',y')=(1,0)
//предыдущее значение, соответствующее промежуточному (A,B):
//(x,y)=(y',x'-[A/B]*y'), где []-целая часть

//решение без помощи рекурсии получить не смог :(
//источник: http://www.e-olimp.com/articles/18

int nodext(int a, int b, int &nod, int &x, int &y){
  int s;
  if(b==0){
    nod=a;
    x=1; y=0; //соответствуют паре (a,b)=(nod,0)
	      //a*x+b*y=nod
	      //nod=1 - если a,b простые числа
    return 0;
  }
  nodext(b,a%b,nod,x,y);
  s=y;
  y=x-(a/b)*y;
  x=s;
}

int main() {
  int a,b,nod,x,y;
  
  cout<<"Введите числа a и b: ";
  cin>>a>>b;

  nodext(a,b,nod,x,y);

  cout<<"nod="<<nod<<"\n"; //т.к. одно из них равно нулю
  cout<<a<<"*x+"<<b<<"*y="<<nod<<"\n";
  cout<<"x="<<x<<"; y="<<y<<"\n";

  return 0;
}
