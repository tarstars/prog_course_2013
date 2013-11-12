#include <iostream>
#include <QRegExp>
#include <QImage>

using namespace std;

int main(int, char **) {
  QRegExp reCircle("circle\\((\\-?[0-9]+),(\\-?[0-9]+)\\),([0-9]+)");
  QRegExp reLine("line\\(([0-9]+),([0-9]+)\\)\\-\\(([0-9]+),([0-9]+)\\)");
  QRegExp reCls("cls");

  int n = 800;
  QImage img(n, n, QImage::Format_ARGB32_Premultiplied);

  string command;
  while(getline(cin, command)) {
    if (reCircle.exactMatch(QString::fromStdString(command))) {
      int cx = reCircle.cap(1).toInt();
      int cy = reCircle.cap(2).toInt();
      int cr = reCircle.cap(3).toInt();
      cout << "circle with x = " << cx << " y = " << cy << " r = " << cr << endl;
      for(int p = 0; p < n; ++p) {
	for(int q = 0; q < n; ++q) {
	  int dx = cx - q;
	  int dy = cy - p; 
	  if (dx * dx + dy * dy < cr * cr) {
	    img.setPixel(q, p, qRgb(0,255,0));
	  }
	}
      }
    } else {
      cout << "no match" << endl;
    }
  }

  img.save("a.png");
  return 0;
}
