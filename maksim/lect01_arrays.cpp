#include <iostream>
using namespace std;

void print(int*, int*);

bool next(int*, int*);

void dec_to_bin(int);

void func(int*, int*);

int main()
{
	cout << " == Part 1 : next() == \n";
	const int n = 5;
	const int k = 3;
	int a[n+k];
  
	for( int i = 0; i < n; i++ ) a[i] = 0;
	for( int i = n; i < n+k ; i++ ) a[i] = 1;
	
	print(a, a+n+k );
	while(next(a, a+n+k)) print(a, a+n+k );

	cout << " == Part 2 : decimal to binary == \n";
	int x;
	cout << "Enter a int number. " << endl;
	cin >> x;
	dec_to_bin(x);

	cout << " == Part 3 : arr[i] = arr[i-1] + arr[i+1] == \n";
	int b[] = { 6, 5, 11, 2, 12, 4 };
	for( int i = 0; i < sizeof(b)/sizeof(b[0]) ; i++)
	  cout << b[i] << " " ; cout << endl;
	func(b, b + sizeof(b)/sizeof(b[0]) );
	for( int i = 0; i < sizeof(b)/sizeof(b[0]) ; i++) 
	  cout << b[i] << " " ; cout << endl;

	return 0;
}

void print(int* begin, int* end)
{
  int *p = begin;
  for( ; p != end; ++p )
    cout << *p ;
  cout << endl;
}

void shift(int *a, int *b, int *z)
{
	int *v, *w;
	for( v = z, w = b; w>=a; --v, --w) *v = *w;
	for( ; v >= a ; --v) *v = 0;
}

bool next(int* begin, int* end)
{
	bool flag = true, ismove=false; 
	int *p, *q, *t;
		
	for( p = begin; p != end; ++p) if ( *p == 1 ) break;
	for( q = end - 1; q != begin-1; --q) if( *q == 1) break;				

	if( p==end-1 ) return false;

	for( t=q ; t!=p; t--)
	{
		if( *(t-1)==0 ) 
		{
			*(t-1) = 1; *t = 0;
			if( t+1 <= q ) shift( t+1 , q, end-1 );
			ismove=true;
			break;
		}
	}
	if(ismove == false)
	{
		if( p != begin )
		{
			*p = 0; *(p-1) = 1;
			shift( p+1, q, end-1 );
		}
		if(p==begin) { flag = false; }
	}
	return flag;
}

void dec_to_bin(int x)
{
	int buf[32], i;
	for( i = 0 ; x != 0; x = x/2, i++ ) { buf[i] = x%2;  } 
	for( i-- ; i>= 0; i--) cout << buf[i]; cout << endl;
}

void func(int* begin, int *end)
{
	int *p = new int[end - begin];
	int *q, *r;
	*p = *begin;
	for( q = begin+1, r=p+1 ; q < end-1; q++, r++) *r = *(q-1) + *(q+1) ;
	*(r) = *(end-1);
	for( r = begin , q = p ; r < end; r++, q++ ) *r = *q;
	delete [] p;
}
