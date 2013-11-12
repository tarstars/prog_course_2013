#include <QImage>
#include <iostream>
#include <cmath>
#include <vector>
#include <conio.h>

using namespace std;

int main(int, char**) {

    int x1, y1, x2, y2;
    x1 = 20;
    y1 = 20;
    x2 = 10;
    y2 = 50;

    // size of image
    int sz = 100;

    QImage img(sz, sz, QImage::Format_ARGB32_Premultiplied);

    // x coordinate of start point (x1,y1) is
    // less than one of final point (x2,y2)
    if(x1 > x2) {
        swap(x1, x2);
        swap(y1, y2);
    }

    // our line
    double k1 = (y2 - y1) / double(x2 - x1);
    double b1 = (y1*x2 - y2*x1) / double(x2 - x1);

    // start pixel
    int x = x1, y = y1;

    vector<int> x_vec(3), y_vec(3);

    while(x <= x2) {
        img.setPixel(x, y, qRgb(255,0,0));

        // next pixels
        x_vec = {{x, x+1, x+1}};
        if(k1 >= 0) {
            y_vec = {{y+1, y+1, y}};
        }
        else {
            y_vec = {{y-1, y-1, y}};
        }

        // perpendicular
        double k2, b2;
        k2 = -1 / k1;

        // distace to line
        vector<double> d(3);
        double x_cross, y_cross;
        for(int i = 0; i < 3; ++i) {
            b2 = y_vec[i] - k2*x_vec[i];
            x_cross = (b2 - b1) / (k1 - k2);
            y_cross = (k2*b1 - k1*b2) / (k2 - k1);
            d[i] = (x_vec[i] - x_cross) * (x_vec[i] - x_cross) +
                   (y_vec[i] - y_cross) * (y_vec[i] - y_cross);
        }

        // choice of next pixel
        double d_min = d[0];
        int i_min = 0;
        for(int i = 1; i < 3; ++i) {
            if(d[i] < d_min) {
                d_min = d[i];
                i_min += 1;
            }
        }
        x = x_vec[i_min];
        y = y_vec[i_min];
    }

    img.save("../line_Bresenhem/line.png");

    return 0;
}
