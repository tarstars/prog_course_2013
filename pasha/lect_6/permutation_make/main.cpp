#include <iostream>
#include "permutation.h"
using namespace std;

int main() {
	
	int a,b, np, yn=1;
	cout<<"Длина permutation: ";
	cin>>np;
	//______________________________________________
	
	permutation perm1(np);
	cout<<"perm1 = "<<perm1<<endl;
	while((yn==1) || (yn==2)) {
		cout<<"swap - 1; next - 2: ";
		cin>>yn;
		if(yn==1) {
			cout<<"perm1.myswap(a,b):  (a,b) = ";
			cin>>a>>b;
			cout<<"perm1.myswap("<<a<<","<<b<<") = ";
			perm1.myswap(a,b);
			cout<<perm1<<endl;
		}
		if(yn==2) {
			cout<<"perm1.next() = ";
			perm1.next();
			cout<<perm1<<endl;
		}
	}
	cout<<endl;
	//______________________________________________
	
	permutation perm2(np);
	cout<<"perm2 = "<<perm2<<endl;
	yn=1;
	while((yn==1) || (yn==2)) {
		cout<<"swap - 1; next - 2: ";
		cin>>yn;
		if(yn==1) {
			cout<<"perm2.myswap(a,b):  (a,b) = ";
			cin>>a>>b;
			cout<<"perm2.myswap("<<a<<","<<b<<") = ";
			perm2.myswap(a,b);
			cout<<perm2<<endl;
		}
		if(yn==2) {
			cout<<"perm2.next() = ";
			perm2.next();
			cout<<perm2<<endl;
		}
	}
	cout<<endl;
	//______________________________________________
	
	permutation perm3=perm1*perm2;
	cout<<"perm3 = perm1*perm2 = "<<perm3<<endl;
	
	
	return 0;
}