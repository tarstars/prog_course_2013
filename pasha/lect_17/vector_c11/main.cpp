#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
#include <algorithm>

using namespace std;

ostream& operator<<(ostream& os, const vector<int>& vec) {
    for(int t : vec) {
        cout << t << " ";
    }
    return os;
}

void f(int x) {
    cout << "ku " << x << endl;
}

int g(int x) {
    return x*x;
}

int main() {
    vector<int> dat = {{1, 3, 4}};
    //cout << dat << endl;

    int cdat[] = {5, 4, 20};

    for_each(begin(dat), end(dat), f); //применяем f к эл-там вектора
    cout << endl;
    for_each(begin(cdat), end(cdat), f);
    cout << "square" << endl;
    //transform(begin(dat), end(dat), begin(dat), g);
    int times = 5;
    auto pred = [=](int x) {return times*x;};
    //auto == function<int(int)>
    //[=] - включаем все переменнные, кот. потребуются
    transform(begin(dat), end(dat), begin(dat), pred); //lambda_function
    cout << dat << endl;
    getch();
    return 1;
}
