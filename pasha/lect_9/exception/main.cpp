#include <iostream>
#include <cmath>

using namespace std;

void solve_sq(int a, int b, int c) {
	if(a==0) {
		throw(string("not square equation"));
	}

	int det = b*b - 4*a*c;
	if(det<0) {
		throw(string("imaginary roots"));
	}
	if(det==0) {
		throw(100500);
	}
	
	cout<<"x12 = "<< (-b+sqrt(det))/2/a << ", "<< (-b+sqrt(det))/2/a << endl;
}

void interactive_solver() {
	int ans=0;
	do {
		int a,b,c;
		cout<<"a, b, c =>";
		cin>>a>>b>>c;
		solve_sq(a,b,c);
		cout<<"1 for continue =>";
		cin>>ans;
	} while(ans==1);
}

int main() {
	try {
		interactive_solver();
	} /*catch(string msg) {
		cout<<"err:"<<msg<<endl;
	} catch(int msg) {
		cout<<"int err: "<<msg<<endl;
	}*/ catch(...) {
		cout<<"ununiversal section"<<endl;
	}
}