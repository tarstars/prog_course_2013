#include <CImg.h>

using namespace cimg_library;

void test_pascal() {
  int n = 600;
  CImg<unsigned char> img(n, n, 1, 3);

  for(int p = 0; p < n; p++) { 
    for(int q = 0; q < n; q++) {
      int val = (p & q) ? 0 : 255;
      img(p, q, 0) = val;
      img(p, q, 1) = val;
    }
  }

  img.save_png("test.png");
}

int main() {
  //test_pascal();

 CImg<unsigned char> image("lena.jpg"), visu(500,400,1,3,0);
  const unsigned char red[] = { 255,0,0 }, green[] = { 0,255,0 }, blue[] = { 0,0,255 };
  image.blur(2.5);
  CImgDisplay main_disp(image,"Click a point"), draw_disp(visu,"Intensity profile");
  while (!main_disp.is_closed() && !draw_disp.is_closed()) {
    main_disp.wait();
    if (main_disp.button() && main_disp.mouse_y()>=0) {
      const int y = main_disp.mouse_y();
      visu.fill(0).draw_graph(image.get_crop(0,y,0,0,image.width()-1,y,0,0),red,1,1,0,255,0);
      visu.draw_graph(image.get_crop(0,y,0,1,image.width()-1,y,0,1),green,1,1,0,255,0);
      visu.draw_graph(image.get_crop(0,y,0,2,image.width()-1,y,0,2),blue,1,1,0,255,0).display(draw_disp);
      }
    }
  return 1;
}
