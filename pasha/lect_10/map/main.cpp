#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
	string val;
	map<string,int> dat;
	
	while(cin>>val) {
		++dat[val];
	}
	
	dat["mama"] = 10;
	
	for(map<string,int>::iterator it = dat.begin(); it != dat.end(); ++it) {
		cout << it -> first << "->" << it -> second << endl;
		//в данном случае: first - string, second - int
	}
	
	return 1;
}
