#include <iostream>
using namespace std;
//_________________________________________________________
//описание класса перестановок

class permutation {
	int n, *pb;
public:
	permutation();
	permutation(int);
	friend std::ostream& operator<< (std::ostream&, const permutation&);
	permutation myswap(int, int);
	permutation operator* (const permutation&);
	permutation operator= (const permutation&);
	permutation next();
	~permutation();
};
//_________________________________________________________
//описание ф-ий класса перестановок

permutation::
permutation(): n(1), pb(new int[1])  {pb[0]=1;}

permutation::
permutation(int nn): n(nn), pb(new int[nn]) {
	for(int i=0; i<n; ++i) {
		pb[i]=i+1;
	}
	cout<<"constructor for: "<<this<<endl;
}

permutation::
~permutation() {
	cout<<"destructor for: "<<this<<endl;
	delete []pb;
}

ostream&
operator<< (ostream &os, const permutation &perm) {
	for(int i=0; i<perm.n; ++i) {
		os<<perm.pb[i];
	}
	return os;
}

permutation permutation::
myswap(int n1, int n2) {
	::swap(pb[n1-1], pb[n2-1]);
	return *this;
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
	cout<<"operator ="<<endl;
	n=b.n;
	delete []pb;
	pb = new int[n];
	for(int i=0; i<b.n; ++i) {
		pb[i] = b.pb[i];
	}
	return *this;
}

permutation permutation::
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
		cout<<"j-1="<<j-1<<";  m="<<m<<endl;
		
		::swap(pb[j-1], pb[m]);
		
		//сортировка пузырьком
		for(int k=0; k<=n-1-j; ++k) {
			for(int i=j; i<=n-1-k; ++i) {
				if(pb[i]>pb[i+1]) {
					::swap(pb[i], pb[i+1]);
				}
			}
		}
	}
	return *this;
}
//_________________________________________________________

int main() {
	int a,b, np, yn;
	cout<<"Длина permutation: ";
	cin>>np;
	//______________________________________________
	
	permutation perm1(np);
	cout<<"perm1 = "<<perm1<<endl;
	yn=1;
	while((yn==1) || (yn==2)) {
		cout<<"swap - 1; next - 2: ";
		cin>>yn;
		if(yn==1) {
			cout<<"perm1.myswap(a,b):  (a,b) = ";
			cin>>a>>b;
			cout<<"perm1.myswap("<<a<<","<<b<<") = "<<perm1.myswap(a,b)<<endl;
		}
		if(yn==2) {
			cout<<"perm1.next() = "<<perm1.next()<<endl;
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
			cout<<"perm2.myswap("<<a<<","<<b<<") = "<<perm2.myswap(a,b)<<endl;
		}
		if(yn==2) {
			cout<<"perm2.next() = "<<perm2.next()<<endl;
		}
	}
	cout<<endl;
	//______________________________________________
	
	permutation perm3=perm1*perm2;
	cout<<"perm3 = perm1*perm2 = "<<perm3<<endl;
	
	//_____________________________________________________________________
	//на все случаи жизни (НЕ РАБОТАЕТ!!!)
	
	/* permutation perm(np), perm1(np), perm2(np);	
	cout<<"perm1 = "<<perm1<<endl;
	int yn=1, p12=1;
	while((p12==1) || (p12==2)) {
		cout<<"perm1 - 1; perm2 - 2: ";
		cin>>p12;
		if(p12==1) {perm=perm1; cout<<"perm (1) - "<<&perm<<endl;}
		if(p12==2) {perm=perm2; cout<<"perm (2) - "<<&perm<<endl;}
		if((p12==1) || (p12==2)) {
			while((yn==1) || (yn==2)) {
				cout<<"swap - 1; next - 2: ";
				cin>>yn;
				if(yn==1) {
					cout<<"perm"<<p12<<".myswap(a,b):  (a,b) = ";
					cin>>a>>b;
					cout<<"perm"<<p12<<".myswap("<<a<<","<<b<<") = "<<perm.myswap(a,b)<<endl;
				}
				if(yn==2) {
					cout<<"perm"<<p12<<".next() = "<<perm.next()<<endl;
				}
			}
			cout<<endl;
		}
		if(p12==1) {perm1=perm;}
		if(p12==2) {perm2=perm;}
	} */
	
	return 0;
}
