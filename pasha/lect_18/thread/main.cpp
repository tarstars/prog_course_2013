#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
#include <conio.h>

using namespace std;
mutex fmut;

void f(int ind, vector<int>* pdat) {
    vector<int> &dat = *pdat;
    bool todo = true;
    while(todo) {
        lock_guard<mutex> lck(fmut);
        if(dat.size()) {
            cout << ind << " " << dat.back() << endl;
            dat.pop_back();
        }
        else {
            todo = false;
        }
        fmut.unlock();
    }
    double s = 0;
    for(long int t = 0; t < 1e8; ++t) {
        s = s + t;
    }
}

int main() {
    vector<int> dat = {{1,3,5,7,9,11,13,15,17,19}};

    const int pn = 10;
    thread pt[pn];

    //многоядерность
    for(int t = 0; t < pn; ++t) {
        pt[t] = thread(f, t+1, &dat); //потоки
    }
    for(int t = 0; t < pn; ++t) {
        pt[t].join();
    }

    getch();
    return 1;
}
