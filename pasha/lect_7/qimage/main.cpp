#include <QImage>
#include <cmath>
#include <sstream>
using namespace std;

int main(int, char**) {
	int n=300;
	for(int k=0; k<240; ++k) {
		QImage sam(n, n, QImage::Format_ARGB32_Premultiplied);
		for(int p=0; p<n; ++p) {
			for(int q=0; q<n; ++q) {
				double dx=q-n/2, dy=p-n/2;
				double r=sqrt(dx*dx+dy*dy);
				double v=sin(r/10 - double(k)/240*3*(2*M_PI));
				double vv=255*(1+v)/2;
				int val=int(vv);
				sam.setPixel(q,p, qRgb(val,val,val)); //0<val<255;
			}
		}
		stringstream dest;
		dest<<k<<"a.jpg";
		sam.save(dest.str().c_str());
	}
	return 0;
}