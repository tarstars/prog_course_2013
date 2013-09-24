#include <iostream>
#include <vector>

using namespace std;

class Decis {
public:
  virtual double f(double, double) const = 0;
  virtual ~Decis(){}
};

class Mult : public Decis {
public:
  virtual double f(double k, double z) const {return k * z;}
};

class NonMult : public Decis {
public:
  virtual double f(double k, double z) const {return k;}
};

vector<Decis*> make_program(int a) {
  vector<Decis*> ret;
  for(;a > 0; a = a / 2) {
    if (a % 2 == 1) {
      ret.push_back(new Mult());
    } else {
      ret.push_back(new NonMult());
    }
  }
  return ret;
}

double
calculate(double x, const vector<Decis*>& prog) {
  double z = x;
  double k = 1;

  for(vector<Decis*>::const_iterator it = prog.begin();
      it != prog.end();
      ++it) {
    k = (*it) -> f(k, z);
    z = z * z;
  }

  return k;
}

void clean_program(const vector<Decis*>& prog) {
  for(vector<Decis*>::const_iterator it = prog.begin();
      it != prog.end();
      ++it) {
    delete *it;
  }
}

double degree(double x, int a) {
  vector<Decis*> prog = make_program(a);
  double k = calculate(x, prog);
  clean_program(prog);
  return k;
}

int main() {
  if (degree(2.0, 10) == 1024) {
    cout << "OK" << endl;
  } else {
    cout << "NOT OK" << endl;
  }

  if (degree(3.0, 5) == 243) {
    cout << "OK" << endl;
  } else {
    cout << "NOT OK" << endl;
  }

  return 0;
}
