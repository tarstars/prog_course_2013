#include <iostream>
#include <fstream>

using namespace std;

int solver(int a, int b, int n) {
	int c=3-a-b; //номер промежуточной башни
	if(n==1){
		cout << a << " " << b << endl;
		return 0;
	}
	solver(a,c,n-1);
	solver(a,b,1);
	solver(c,b,n-1);
	return 1;
}

int main() {
	int a,b,n;
	
	//echo откуда куда колец ...
	//echo 0 1 3 |./solver.exe|./emul.exe
	
	//cout<<"Номер исходной башни: ";
	cin>>a;
	//cout<<"Номер конечной башни: ";
	cin>>b;
	//cout<<"Число колец: ";
	cin>>n;
	cout<<n<<endl;
	
	solver(a,b,n);
	
	return 0;
}

