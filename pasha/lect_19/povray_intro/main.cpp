#include <iostream>
#include <fstream>
#include <cmath>
#include <conio.h>

using namespace std;

int main() {
    ofstream dest("../povray_intro/scene.pov");

    for(double phi = 0; phi < 2*M_PI; phi += 0.01) {
        double x = sin(7*phi);
        double y = sin(5*phi);
        dest << "sphere{<" << x << ", 0, " << y << "> 0.05 "
                " pigment{color <1,0,0>}}" << endl;
    }
    cout << "end" << endl;
    getch();
    return 0;
}
