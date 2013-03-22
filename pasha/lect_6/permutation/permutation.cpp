#include <iostream>
#include "permutation.h"

permutation::permutation(): n(1), pb(new int[1])  {pb[0]=1;}

permutation::permutation(int nn): n(nn), pb(new int[nn]) {
	for(int i=0; i<n; ++i) {pb[i]=i;}
}

ostream&
operator<< (ostream &os, const permutation &perm) {
	for(int i=0; i<n; ++i) {os<<perm.pb[i]<<" ";}
	return os;
}

void swap(int n1, int n2) {
	::swap(pb[n1], pb[n2]);
}

void next() {
	int j=n-1;
    int *pe=pb+j;
  
    while( (pb[j-1]>pb[j])  &&  (j>=1) ) {
		--j; //ищем эл-т, левее которого ничего не трогаем
    }
    if(j==0) {
		cout<<"???\n"<<"Операция next невозможна!"<<endl;
	}
    else {
		int m=n-1;
		for(int i=n-2; i>=j; --i) {
			if( (pb[i]>pb[j-1]) && (pb[i]<pb[n-1]) ) {
				m=i; //поиск эл-та, которй нужно поменять с pb[j]
			}
			if(pb[i]>pb[i+1]) {
				::swap(pb[i], pb[i+1]); //от нечего делать начинаем сортировку
			}
		}
		
		::swap(pb[j-1], pb[m]);
		
		for(int k=0; k<n-j-3; ++k) {
			for(int i=n-2-k; i>=j; --i) {
				if(pb[i]>pb[i+1]) {
					::swap(pb[i], pb[i+1]); //сортировка пузырьком
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
1 3 2 4 5
1 3 4 2 5
1 3 4 5 2
1 4 2 3 5

1)идём справа налево по не найдём j: pb[j-1]<pb[j]
2)идём ещё раз и ищем min из пройденных значений pb[m]>pb[j-1]
3)меняем местами pb[m] и pb[j-1]
4)расставляем числа с i>(j-1) в порядке возрастания слева направо
*/