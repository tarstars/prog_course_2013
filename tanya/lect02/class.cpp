#include <iostream>
#include <vector>
using namespace std;
void print(vector<double>& arr){
  for(int i=0;i<arr.size();++i){
    cout<<arr[i]<<" ";
  }
}
void print1(vector<double>::iterator it, int n) {
  for(int i=0;i<n;++i){
    cout<<*it<<" ";
    ++it;
  }
}
void print2(vector<double>::iterator itb, vector<double>::iterator ite)
{while(itb<ite){
    cout<<*(itb++)<<" "; 
 }
}
int main(){
  int n;
  cin>>n; 
  vector<double> dat (n);
  //double *pd=&(dat[5]); //хотим указательна 5 элемент, сработает, только если вектор не от boll (старый инструментарий)
  // dat.push_back(5.0);//добавляет к массиву еще один элемент
 //для нового иструментария есть итераторы, работаюи, как указатели
 vector<double>::iterator itb=dat.begin();//первый эл-т
 vector<double>::iterator ite=dat.end();// элемент, идущий за последним
 for(int t=0;t<n; ++t){
   dat[t]=t;}  
print(dat);
 cout<<"1) *itb= "<<*itb<<endl;
 itb++;
 cout<<"2) *itb= "<<*itb<<endl;
   itb+=2;
   cout<<"3) *itb= "<<*itb<<endl;
   print1(itb,n);
   print2(itb,ite);
}
