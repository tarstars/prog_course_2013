#include <iostream>
#include "permutation.h"
using namespace std;

int main() {
	
	permutation perm1(5);
	
	cout<<"perm1 = "<<perm1<<" -> ";
	cout<<"swap(1,4) -> "<<perm1.swap(1,4)<<endl;;
	
	permutation perm2(5), perm(5);
	
	cout<<"perm2 = "<<perm2<<" -> ";
	cout<<"swap(1,3) -> "<<perm2.swap(1,3);
	cout<<" -> swap(2,5) -> "<<perm2.swap(2,5);
	cout<<" -> next() -> "<<perm2.next()<<endl;
		
	perm=perm1*perm2;
	cout<<"perm = perm1*perm2 = "<<perm<<endl;
	
	return 0;
}

