#include "fftwmatrix.h"
#include "fftwplan.h"

#undef main

using namespace std;

FFTWMatrix load_matrix(const char*);
FFTWMatrix mult(FFTWMatrix&, FFTWMatrix&);
void save_to_file(FFTWMatrix&, const char*);
void normalize(FFTWMatrix&);

int main() {
  FFTWMatrix a = load_matrix("a.bmp");
  FFTWMatrix b = load_matrix("b.bmp");
  
  int w = a.width();
  int h = a.height();

  FFTWMatrix ss(h, w), ds(h, w), sb(h, w), db(h, w), af(h, w), bf(h, w);
  FFTWPlan ps(ss, ds, FORWARD), pb(sb, db, FORWARD);
  
  ss.take_from(a);
  ps.execute();
  af.take_from(ds);

  sb.take_from(b);
  pb.execute();
  bf.take_from(db);
  
  FFTWMatrix cf = mult(af, bf);
  FFTWMatrix cc(h,w);
  
  FFTWPlan cs(cf, cc, BACKWARD);
  cs.execute();

  normalize(cc);
  
  save_to_file(cc, "c.bmp");
  
  return 0;
}
