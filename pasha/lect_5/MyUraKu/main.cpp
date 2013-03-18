#include<iostream>
using namespace std;

int main() {
	#ifdef KU	//выполняется до начала компиляции
				//если определён KU, то выполняем ...
				//-Dwww => следующий символ (www) определён
	cout<<"ku"<<endl;
	#endif
	
	#ifdef URA
	cout<<"ura!"<<endl;
	#endif
}