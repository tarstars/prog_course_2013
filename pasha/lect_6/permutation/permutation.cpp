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
		--j;
    }
    if(j==0) {
		cout<<"???\n"<<"Операция next невозможна!"<<endl;
	}
    else {
		::swap(pb[j-1], pb[j]);
    
		
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

1)идём справа налево по не найдём i=ii: pb[ii-1]<pb[ii]
2)идём ещё раз и ищем min из пройденных значений pb[m]>pb[ii-1]
3)меняем местами pb[m] и pb[ii-1]
4)расставляем числа с i>(ii-1) в порядке возрастания слева направо
*/