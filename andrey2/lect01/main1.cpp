/*Лекция 01

01.1) Вывести геометрическую прогрессию с 1 до 2000 со знаменателем 2. for, while

Сочетания:
01.2) Создать массив с заданным количеством 0 и 1
   create_array(int*, int n, int k)
   create_array(pa, 5, 3) -> pa={0, 0, 1, 1, 1}

01.3) Написать функцию print, распечатывающую состояние массива
   print(int*, int)
   print(int*, int*)

01.4) Распечатать все сочетания: функция next, переводящую текущее состояние в следующее.
   bool next(int*, int*)

01.5) Сдвинуть элементы массива на k позиций по циклу
    a) С использованием дополнительного массива
    b*) В том же массиве

01.6) Заменить элементы массива на сумму
    a) С использованием дополнительного массива
    b*) В том же массиве

01.7) Распечатать двоичное представление числа*/

//------------------------------------------------------------------

#include <iostream>
#include <math.h>
using namespace std;

void output_progression (int a, int q);
void create_array(int *pa, int n, int k);
void print1(int *pa, int sz);
void print2(int *pb, int *pe);
void print3(int *pb, int sz);
void swap(int &x, int &y);
bool next(int *pa, int sz);
void reverse(int *pb, int *pe);
void shift(int *pa, int n, int k);
void summ(int *pa, int n);
void output_bin();

int main()
{

  output_progression(1, 2);

  //--------------------------------------------------

  int n, k, i, sz;

  cout << "Input n and k to generate structure with n '1' and k '0' (like that - 01000011):" << endl;
  cin >> n >> k;
  sz = n+k;

  int *pa = new int [sz];
  int *pb;
  int *pe;
  pb = pa;
  pe = pa+sz;

  create_array(pa, n, k);

  do
  {
    print1(pa, sz);
  }
  while( next(pa, sz) );

  cout << "Let's check our 'print' functions:" << endl;
  print1(pa, sz);
  print2(pb, pe);

  delete []pa;

  //--------------------------------------------------

  cout << "Input n - size of array:" << endl;
  cin >> n;
  cout << "And now input array:" << endl;

  int *pm = new int [n];

  i = 0;
  while( i < n )
    {
      cin >> pm[i];
      i++;
    }

  cout << "Input k and I'll shift your array:" << endl;
  cin >> k;

  shift (pm, n, k % n);

  print3(pm, n);

  cout << "And now I'll change yor array (a[i] = a[i-1]+a[i+1]):)" << endl;

  summ(pm, n);

  print3(pm, n);

  delete []pm;

  //--------------------------------------------------

  output_bin();

  //--------------------------------------------------

  cout << endl << "That's all" << endl;
  return 0;

}

void output_progression (int a, int q)
{
  while( a < 2000 )
  {
    cout << a << " ";
    a = a*q;
  }
  cout << endl;

  for( a = 1; a < 2000; a = a*q)
  {
    cout << a << " ";
  }
  cout << endl;
}

void print1(int *pa, int sz)
{
  for(int i = 0; i < sz; ++i)
  {
    cout << *pa;
    ++pa;
  }
  cout << endl;
}

void print2(int *pb, int *pe)
{
  int sz = pe-pb;
  for(int i = 0; i < sz; ++i)
  {
    cout << *pb;
    ++pb;
  }
  cout << endl;
}

void print3(int *pa, int sz)
{
  for(int i = 0; i < sz; ++i)
  {
    cout << *pa << " ";
    ++pa;
  }
  cout << endl;
}

void swap(int &x, int &y)
{
  int t;
  t = x;
  x = y;
  y = t;
}

bool next(int *pa, int sz)
{
  int j = sz-2;
  while( j!=-1 && pa[j] >= pa[j+1] )
    j--;
  if (j == -1)
    return false;
  int k = sz - 1;
  while( pa[j] >= pa[k] )
    k--;
 
  swap(pa[j],pa[k]);
 
  int l = j + 1, r = sz - 1;
  while( l<r )
    swap(pa[l++],pa[r--]);
  return true;
}

void create_array(int *pa, int n, int k)
{
  int sz = n+k;
  for(int i = 0; i < sz-n; ++i)
    pa[i] = 0;
  for(int i = sz-n; i < sz; ++i)
    pa[i] = 1;
}

void reverse(int *pb, int *pe)
{
  int temp;
  while( pe > pb )
    {
      swap(*pe, *pb);
      pe--;
      pb++;
    }
}

void shift(int *pa, int n, int k)
{
  reverse(pa+n-k, pa+n-1);
  reverse(pa, pa+n-k-1);
  reverse(pa, pa+n-1);
}

void summ(int *pa, int n)
{
  int temp = pa[0];
  for( int i = 1; i < n-1; ++i)
    {
      swap(temp, pa[i]);
      pa[i] = pa[i] + pa[i+1];
    }
}

void output_bin()
{
  int i, num, num_len, temp;
  cout << "Input some numbers and I'll show it in binary representation:" << endl;
 
  while(cin >> num)
  {
    if(num == 0){
      cout << num << " =  0" << endl;
      continue;
    }
    if(num < 0){
      num = -num;
      cout << "--";
    }
    cout << num << " = ";

    num_len=int(log(num)/log(2))+1;
    for(i=num_len-1; i>=0; --i){
      temp = (num >> i) & 1;
      cout << temp;
    }

    cout << endl;
  }
}
