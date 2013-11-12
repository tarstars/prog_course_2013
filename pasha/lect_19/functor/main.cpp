#include <iostream>
#include <vector>
#include <algorithm>
#include <conio.h>

using namespace std;

ostream& operator <<(ostream& os, const vector<int>& r) {
    for(int t : r) {
        os << t << " ";
    }
    return os;
}

void f(int t) {
    cout << t << " ";
}

class OurFunctor {
    int s;
public:
    OurFunctor() : s(0) {}
    void operator ()(int t) {s += t;}
    int GetValue() {return s;}
};

int main() {
    vector<int> dat = {{30,40,50,60,12,19,25,20,20,20}};

    cout << dat << endl;
    for_each(begin(dat), end(dat), f);

    OurFunctor summ;
    OurFunctor real_summ = for_each(begin(dat), end(dat), summ);
    cout << "summ is " << real_summ.GetValue() << endl;

    getch();
}
