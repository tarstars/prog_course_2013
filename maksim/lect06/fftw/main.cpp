#include "fftwmatrix.h"
#include "fftwplan.h"

using namespace std;

FFTWMatrix load_matrix(const char*);
FFTWMatrix mult(FFTWMatrix&, FFTWMatrix&);

int main() {
  FFTWMatrix a = load_matrix("aa.bmp");
  FFTWMatrix b = load_matrix("bb.bmp");

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
  save_to_file(cc, "c.bmp");

  return 0;
}

FFTWMatrix mult(FFTWMatrix& m1, FFTWMatrix& m2) {
  int h = m1.height(), w = m1.width();
  FFTWMatrix ans(h, w);
  for(int p = 0; p < h; p++)
    for(int q = 0; q < w; q++) {
      ans.pA[p*w+q][0] = (m1.at(p,q)*m2.at(p,q)).real();
      ans.pA[p*w+q][1] = (m1.at(p,q)*m2.at(p,q)).imag();
    }
  return ans; 
}
