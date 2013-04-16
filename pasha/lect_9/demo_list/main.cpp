#include <iostream>
#include <list>
#include <vector>

using namespace std;

template<typename T>
ostream& print(ostream& os, T itb, T ite) {
	for(; itb != ite; ++itb) {
		os<<*itb<<" ";
	}
	return os;
}

int main() {
	int n, t1=0, t2=0;
	
	cout<<"Введите кол-во букв: ";
	cin>>n;
	vector<list<char> > dat(3);
	
	for(int i=0; i<n; ++i) {
		dat[0].push_back('a'+i);
	}
	for(int i=0; i<3; ++i) {
		print(cout, dat[i].begin(), dat[i].end()) << endl;
		cout<<"_________________"<<endl;
	}
	
	while((t1==0 || t1==1 || t1==2) && (t2==0 || t2==1 || t2==2)) {
		cout<<"Перестановка с t1 на t2: ";
		cin>>t1>>t2;
		dat[t2].push_back(dat[t1].back());
		dat[t1].pop_back();
		for(int i=0; i<3; ++i) {
			print(cout, dat[i].begin(), dat[i].end()) << endl;
			cout<<"_________________"<<endl;
		}
	}
}