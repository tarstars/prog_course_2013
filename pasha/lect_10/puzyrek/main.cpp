#include <iostream>
#include <list>
#include <vector>

using namespace std;

list<int>::iterator f(list<int>::iterator l_itb, int n) {
	list<int>::iterator itb = l_itb;
	for(int k=0; k<n-1; ++k) {
		++itb;
	}
	return itb;
}

int size_list(list<int>::iterator l_itb, list<int>::iterator l_ite) {
	int n=0;
	while(l_itb != l_ite) {
		++l_itb;
		++n;
	}
	return n;
}

int size_vect(vector<int>::iterator v_itb, vector<int>::iterator v_ite) {
	int n=0;
	while(v_itb != v_ite) {
		++v_itb;
		++n;
	}
	--n;
	return n;
}

int main() {
	list<int> l;
	vector<int> v;
	int n;
	
	cout<<"Введите числа через пробел: ";
	while(cin>>n) {
		//ctrl+c + ctrl+d  =  конец ввода
		l.push_back(n);
		v.push_back(n);
	}
	cout << endl;
	
	list<int>::iterator l_itb = l.begin();
	list<int>::iterator l_ite = l.end();
	
	vector<int>::iterator v_itb = v.begin();
	vector<int>::iterator v_ite = v.end();
	
	//for(int i=(v_ite-v_itb)/sizeof(int); i>0; --i) {
	for(int i=size_vect(v_itb, v_ite); i>0; --i) {
		for(int j=0; j<i; ++j) {
			if(v[j]>v[j+1]) {
				int tmp = v[j+1];
				v[j+1] = v[j];
				v[j] = tmp;
			}
		}
	}
	
	for(int i=size_list(l_itb, l_ite); i>0; --i) {
		for(int j=0; j<i; ++j) {
			if(*f(l_itb,j) > *f(l_itb,j+1)) {
				int tmp = *f(l_itb,j+1);
				*f(l_itb,j+1) = *f(l_itb,j);
				*f(l_itb,j) = tmp;
			}
		}
	}
	
	cout << "Отсортированный список" << endl;
	for(; l_itb != l_ite; ++l_itb) {
		cout << *l_itb << " ";
	}
	cout << endl;
	
	cout << "Отсортированный вектор" << endl;
	for(; v_itb != v_ite; ++v_itb) {
		cout << *v_itb << " ";
	}
	cout << endl;
	
	return 1;
}
