#include <QImage>
#include <cmath>

using namespace std;

int main(int, char**) {

    int sz = 100;
    int r = 10;

    int x_center = sz/2, y_center = sz/2;
    QImage img(sz, sz, QImage::Format_ARGB32_Premultiplied);

    int x = x_center, y = y_center + r;

    int Ds, Dt;

    while(x < x_center + r/sqrt(2)) {
        img.setPixel(x, y, qRgb(255,0,0));
        img.setPixel(x - 2*(x-x_center), y, qRgb(255,0,0));

        img.setPixel(x, y - 2*(y-y_center), qRgb(255,0,0));
        img.setPixel(x - 2*(x-x_center), y - 2*(y-y_center), qRgb(255,0,0));
        //_____

        img.setPixel(y, x, qRgb(255,0,0));
        img.setPixel(y, x - 2*(x-x_center), qRgb(255,0,0));

        img.setPixel(y - 2*(y-y_center), x, qRgb(255,0,0));
        img.setPixel(y - 2*(y-y_center), x - 2*(x-x_center), qRgb(255,0,0));
        //_____

        Ds = (x + 1 - x_center)*(x + 1 - x_center) +
             (y - y_center)*(y - y_center) - r*r;
        Dt = (x + 1 - x_center)*(x + 1 - x_center) +
             (y - 1 - y_center)*(y - 1 - y_center) - r*r;
        if(abs(Ds) < abs(Dt)) {
            x = x + 1;
        }
        else {
            x = x + 1;
            y = y - 1;
        }
    }

    img.save("../circle_Bresenhem/circle.png");
    return 0;
}
