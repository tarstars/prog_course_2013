#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

bool is_good(int t) {return t%2 == 1;}

int main() {
	vector<int> dat;
	for(int t=0; t<20; ++t) {
		dat.push_back(t);
	}
	//copy(dat.begin(), dat.end(), ostream_iterator<int>(cout, ", "));
	copy_if(dat.begin(), dat.end(), ostream_iterator<int>(cout, ", "), is_good);
	
	return 0;
}