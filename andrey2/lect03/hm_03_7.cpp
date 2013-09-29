#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

using namespace std;

//---------------------------------------------------------

void print(vector<double>& arr);
void my_qsort(vector<double>& arr, int itb, int ite);
void swap(double &x, double &y);

//---------------------------------------------------------

int main(int argc, char* argv[])
{
  
  if (argc <3)
  {
    cerr << "usage: 'hm_03_7 in.txt out.txt' qsorts in.txt" << endl;
    return 1;
  }

  ifstream in_arg(argv[1]);
  ofstream out_arg(argv[2]);

  double x;
  vector<double> arr;
  vector<double>::iterator itb = arr.begin();
  vector<double>::iterator ite = arr.end();
  int n = 0;

  while( in_arg >> x )
  {
    arr.push_back(x);
    ite++;
  }
  
  n = ite-itb;
  print(arr);
  my_qsort(arr, 0, (int)arr.size()-1);
  print(arr);

  for(int i = 0; i < (int)arr.size(); ++i)
  {
    out_arg << arr[i] << " ";
  }

  return 0;

}

//---------------------------------------------------------

void print(vector<double>& arr)
{
  for(int i = 0; i < (int)arr.size(); ++i)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}

void my_qsort(vector<double>& arr, int itb, int ite)
{
  int ib = itb;
  int ie = ite;
  int x;

  double p = arr[(int)((ib+ie)/2)];
  do
  {
    while( arr[ib] < p ) ++ib;
    while( arr[ie] > p ) --ie;
    if( ib <= ie )
    {
      swap(arr[ib], arr[ie]);
      ++ib;
      --ie;
    }
  }
  while( ib < ie );
  if( itb < ie ) my_qsort(arr, itb, ie);
  if( ite > ie ) my_qsort(arr, ib, ite);
}

void swap(double &x, double &y)
{
  double t;
  t = x;
  x = y;
  y = t;
}
