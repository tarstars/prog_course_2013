#include <iostream>
#include "permutation.h"
using namespace std;

permutation::
permutation(): n(1), pb(new int[1])  {pb[0]=1;}

permutation::
permutation(int nn): n(nn), pb(new int[nn]) {
	for(int i=0; i<n; ++i) {
		pb[i]=i+1;
	}
	//cout<<"constructor for: "<<this<<endl;
}

permutation::
~permutation() {
	//cout<<"destructor for: "<<this<<endl;
	delete []pb;
}

ostream&
operator<< (ostream &os, const permutation &perm) {
	for(int i=0; i<perm.n; ++i) {
		os<<perm.pb[i];
	}
	return os;
}

void permutation::
myswap(int n1, int n2) {
	::swap(pb[n1-1], pb[n2-1]);
}

permutation permutation::
operator* (const permutation& b) {
	permutation perm(b.n);
	for(int i=0; i<b.n; ++i) {
		perm.pb[i] = pb[b.pb[i]-1];
	}
	return perm;
}

permutation permutation::
operator= (const permutation& b) {
	n=b.n;
	delete []pb;
	pb = new int[n];
	for(int i=0; i<b.n; ++i) {
		pb[i] = b.pb[i];
	}
	//cout<<"operator ="<<endl;
	return *this;
}

void permutation::
next() {
	int j=n-1;
  
    while( (pb[j-1]>pb[j])  &&  (j>=1) ) {
		--j; //ищем эл-т, левее которого ничего не трогаем
    }
    if(j==0) {
		cout<<"Операция next невозможна!"<<endl;
	}
    else {
		//поиск эл-та, который нужно поменять с pb[j-1]
		int m,k=0;
		for(int i=n-1; i>=j; --i) {
			if((k==0) && (pb[i]>pb[j-1])) {
				m=i;
				++k;
			}
			if((k!=0) && (pb[i]>pb[j-1]) && (pb[i]<pb[m])) {
				m=i;
			}
		}
		//cout<<"j-1="<<j-1<<";  m="<<m<<endl;
		
 		::swap(pb[j-1], pb[m]);
		
		//сортировка пузырьком
		for(int k=1; k<=n-1-j; ++k) {
			for(int i=j; i<=n-1-k; ++i) {
				if(pb[i]>pb[i+1]) {
					::swap(pb[i], pb[i+1]);
				}
			}
		}
	}
}

/*
next()

1 2 3 4 5
1 2 3 5 4
1 2 4 3 5
1 2 4 5 3
1 2 5 3 4
1 2 5 4 3
1 3 2 4 5

1)идём справа налево по не найдём j: pb[j-1]<pb[j]
2)идём ещё раз и ищем min из пройденных значений pb[m]>pb[j-1]
3)меняем местами pb[m] и pb[j-1]
4)расставляем числа с i>(j-1) в порядке возрастания слева направо
*/