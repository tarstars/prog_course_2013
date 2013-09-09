//заяц (x1,y1) бежит вдоль оси Ох со скоростью v1, а лиса (x2,y2) - в сторону зайца с v2.
//Начальное расстояние между ними L0. Через какое время они встретятся?

#include <iostream>
#include <cmath>
using namespace std;

int main() {
	double v1 = 2, v2 = 1;
	while(v2<=v1) {
		cout << endl << endl;
		cout << "Введите cкорость зайца: ";
		cin >> v1;
		cout << "Введите cкорость лисицы: ";
		cin >> v2;
	}
	
	double L, L0;
	cout << "Введите начальное расстояние: ";
	cin >> L0;
	L = L0;
	
	double x1 = 0; //y1 = 0
	double x2 = 0, y2 = L;
	double t = 0, dt = (L/v2) / 1000;
	double phi;
	
	while(L > L0/1000) {
		phi = atan((x1 - x2) / y2);
		x2 = x2 + v2 * sin(phi) * dt;
		y2 = y2 - v2 * cos(phi) * dt;
		x1 = x1 + v1 * dt;
		L = sqrt((x1-x2)*(x1-x2) + y2*y2);
		t = t + dt;
	}
	cout << "Лиса догонит зайца в момент t = " << t << endl;
	cout << "Точное решение: t = " << (L0/v2) / (1 - v1*v1/v2/v2) << endl;
	return 1;
}