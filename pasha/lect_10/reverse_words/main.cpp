#include <iostream>
#include <list>

using namespace std;

int main() {
	list<string> words;
	string w;
	
	cout<<"Введите слова через пробел: ";
	while(cin>>w) {
		//ctrl+c + ctrl+d  =  конец ввода
		words.push_back(w);
	}
	
	cout << endl;
	
	list<string>::reverse_iterator itb = words.rbegin();
	list<string>::reverse_iterator ite = words.rend();
	for(; itb != ite; ++itb) {
		cout<<*itb<<" "; //выводим в обратном порядке
	}
	
	cout << endl;
	
	return 1;
}
