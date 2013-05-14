#include <iostream>
#include <map>
using namespace std;

map<int,int> freq, val;

int f(int n) {
	++freq[n];
	if(val.find(n)!=val.end()) {
		return val[n];
	}
	if(n<2) {
		val[n]=1;
		return 1;
	}
	val[n] = val[n-1] + val[n-2];
	return val[n];
}

int main() {
	int t = f(8);
	cout<<endl;
	cout<<t<<endl;
	for(map<int,int>::iterator it = freq.begin(); it!=freq.end(); ++it) {
		cout << it->first << " -> " << it->second << endl; 
	}
	
	return 0;
}