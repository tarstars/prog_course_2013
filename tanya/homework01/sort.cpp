#include <iostream>
using namespace std;
int main()
{
  int a[10], b[10], c[10];
  int k;
  //заполняем массив числами   
 
 for (  int i = 0; i < 10; ++i)
    { 
      a[i]=4*i+i-7;
      cout<<a[i]<<" ";}
 cout<<endl;
 // сдвигаем с помощью доп массива влево
 cout << "Shift with array" << endl;
cout << "vvedite sdvig: " << endl;
 cin >> k;
 cout << endl; 
 
  for (int i = 0; i < 10; ++i)
   {int g= i + k;
     if(g > 9) g = g - 10;
     b[g] = a[i];
    
   }
 for ( int i = 0; i < 10; ++i)
   {
cout << b[i] << " ";
   }
   cout <<  endl;
 

//складываем при помощи вспомогат массива  
   cout << " sum with array " << endl;
 for( int j=0;j<10;j++)
   { if(j==0) 
         {c[j]=a[j];
       
	  }
     else
       {
	 if(j==9)	   
             {c[j]=a[j];
     	       
		 }
      else  {c[j]=a[j-1]+a[j+1];
	
	     }
	     }
     cout<<c[j]<<" ";     
}
    
cout<<endl;
 
 // сдвигаем без помощи  вспомогательного массива вправо
 cout << "shift without array" << endl;
for (int i = 0; i < k; ++i){
  int alast = a[9];
    for (int j = 9; j > 0; j-- ){
      a[j] = a[j-1];
    }
      a[0] = alast;
    
 }
 for(int i = 0; i < 10; ++i){
    cout << a[i] << " ";
  } 
 cout << endl;
 // складываем без доп массива
 cout << "sum wihtout array" << endl;
   int h=a[0];
   int d=a[1]; 
for (int i = 0 ; i < 10; ++i)  {
   if (i == 0) a[i]=a[0];
   else{ 
     if(i==9) a[i]=a[9];
     else{
  
   a[i]=h+a[i+1];
   h=d;
   d=a[i+1];
     }
}
 
   cout << a[i] << " ";}
 cout << endl;
}

