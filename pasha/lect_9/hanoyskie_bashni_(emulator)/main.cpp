#include <iostream>
#include <list>
#include <vector>

using namespace std;

int emulator(vector<list<char> >& dat, int a, int b) {
	
	dat[b].push_back(dat[a].back());
	dat[a].pop_back();
	
	for(int i=0; i<3; ++i) {
		list<char>::iterator itb = dat[i].begin();
		cout << i << ") ";
		for(; itb != dat[i].end(); ++itb) {
			cout << *itb;
		}
		cout << "  ";
	}
	cout << endl;
	
	return 0;
}

int main() {
	vector<list<char> > dat(3);
	int a,b,n;
	
	cout<<"Эмулятор ханойских башен\n";
	
	cout<<"Число колец: ";
	cin>>n;
	for(int i=0; i<n; ++i) {
		dat[0].push_back('A'+i);
	}
	
	emulator(dat,0,0);
	
	cout<<"Откуда -> куда (0,1,2):\n";
	
	while(cin>>a>>b) {
		//ctrl+c + ctrl+d  =  конец ввода
		emulator(dat,a,b);
	}
	
	return 0;
}

