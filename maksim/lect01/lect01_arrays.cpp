#include <iostream>
using namespace std;

int* create_array(int, int);

void print( int*, int* );
void print( int*, int );

bool next( int*, int* );

void dec_to_bin( int );

void func_sum( int*, int*);
void func_sum_adv( int*, int*);

void shift( int*, int*, int);
void shift_adv( int*, int*, int);

int main()
{
  cout << "Part 0: for- and while- loops: " << endl;
  cout << "for-loop: " << endl;
  for( int z = 1, q = 2; z < 2000; z *= q )
    cout << z << endl;

  cout << endl << "while-loop: " << endl;
  int z = 1, q = 2;
  while( z < 2000)
    {
      cout << z << endl;
      z *= q;
    }
  cout << endl << "Part 1: create_array" << endl;
  int *a;
  int n = 8, k = 3;
  a = create_array( n, k);
  print( a, a + n);
  
  cout << endl << "Part 2: print( int *, int *), print(int*, int) " << endl;
  print( a, a + n);
  print( a, n);
  
  cout << endl << "Part 3: next() " << endl;
  while( next( a, a + n) ) print( a, a + n);

  cout << endl << "Part 4: shift() and shift_adv() " << endl;
  int b[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  print( b, sizeof(b)/4 );
  k = 5;
  shift( b, b + sizeof(b)/4 , k);
  print( b, sizeof(b)/4 );
  shift_adv( b, b + sizeof(b)/4 , k);
  print( b, sizeof(b)/4 );

  cout << endl << "Part 5: func_sum() and func_sum_adv() " << endl;
  int bb[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  print( bb, sizeof(bb)/4 );
  func_sum( bb, bb + sizeof(bb)/4 );
  print( bb, sizeof(bb)/4 );
  func_sum_adv( bb, bb + sizeof(bb)/4 );
  print( bb, sizeof(bb)/4 );

  cout << endl << "Part 6: decimal to binary " << endl;
  int x;
  x = 10;
  cout << x << " ";
  dec_to_bin(x);
  x = 100;
  cout << x << " ";
  dec_to_bin(x);
  x = 1023;
  cout << x << " ";
  dec_to_bin(x);
  
  return 0;
}

int* create_array(int n, int k)
{
  int *pa = new int[n];
  for(int i = 0; i < n; i++) pa[i] = 0; 
  for(int i = n-k; i < n; i++) pa[i] = 1;
  return pa; 
}

void print(int* begin, int* end)
{
  int *p = begin;
  for( ; p != end; ++p )
    cout << *p << " ";
  cout << endl;
}

void print(int* begin, int n)
{
  int *p = begin;
  for( ; p != begin + n; ++p )
    cout << *p << " ";
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

void func_sum(int* begin, int *end)
{
  int *p = new int[end - begin];
  int *q, *r;
  *p = *begin;
  for( q = begin+1, r=p+1 ; q < end-1; q++, r++) *r = *(q-1) + *(q+1) ;
  *(r) = *(end-1);
  for( r = begin , q = p ; r < end; r++, q++ ) *r = *q;
  delete [] p;
}

void func_sum_adv(int* pa, int* pe)
{
  int x, y, i;

  for( i = 1, x = pa[0]; i < (int)(pe - pa - 1) ; ++i) {  
    y = pa[i];
    pa[i] = x + pa[i+1];
    x = y;
  }
}

void shift(int *pa, int *pb, int k)
{
  int n = pb - pa;
  int *pAu = new int[n];
  for( int i = 0; i < n; i++) pAu[ ( i + k ) % n ] = pa[i];
  for( int i = 0; i < n; i++) pa[i] = pAu[i];
  delete [] pAu;
}
  
void shift_adv(int *pa, int *pb, int k)
{
  int n = pb - pa;
  int* begin = pa;
  int x, j = 1;
  for(int i = k % n; ; i = (i + k) % n) 
    {
      x = *(pa + i);
      *(pa + i) = *pa;
      *pa = x;
      j++;
      if( i == 0 && j < n - 1) ++pa;
      if( i == 0 && j >= n - 1) break;
    } 
}
