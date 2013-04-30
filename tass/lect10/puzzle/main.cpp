#include <iostream>

using namespace std;

bool gb(unsigned char c, int ind) {
  return (c & (1 << ind)) != 0;
}

ostream& pprint(ostream &os, unsigned char c) {
  os << int(c) << "\\n";
  os << (gb(c, 6) ? "  | *" : "* |  ") << "\\n";
  for(int t = 0; t < 3; ++t) {
    string val("  |  ");
    val[gb(c, t) ? 3 : 0] = '1' + t;
    val[gb(c, t + 3) ? 4 : 1] = 'a' + t;
    os << val << "\\n";
  }
  return os;
}

bool valid_state(unsigned char b) {
  for(int t = 0; t < 3; ++t) { // t - student
    bool ss = gb(b, t + 3);
    bool ts = gb(b, t);
    if (ss != ts) {
      for(int p = 0; p < 3; ++p) { //p - enemy teacher
	if (p != t) {
	  if (gb(b, t + 3) == gb(b, p)) {
	    return false;
	  }
	}
      }
    }
  }
  return true;
}

bool can_go(unsigned char a, unsigned char b) {
  if (!valid_state(b))
    return false;

  bool boat_a = gb(a, 6);
  bool boat_b = gb(b, 6);
  if (boat_a == boat_b) 
    return false;
  
  int s = 0; 
  for(int t = 0; t < 6; ++t) {
    bool pa = gb(a, t);
    bool pb = gb(b, t);
    if (pa != pb) {
      if (pa != boat_a)
	return false;
      ++s;
    }
  }

  if (s < 1 || s > 2) 
    return false;


  return true;
}

ostream&
print_graph(ostream& os) {
  os << "graph t {" << endl;
  for(unsigned char p = 0; p < 128; ++p) {
    for(unsigned char q = 0; q < p; ++q) {
      if (valid_state(p) && valid_state(q) && can_go(p, q)) {
	os << int(p) << "--" << int(q) << ";" << endl;
      }
    }
  }
  
  for(unsigned char t = 0; t < 128; ++t) {
    if (valid_state(t)) {
      os << int(t) << "[label = \"";
      pprint(os, t) << "\"];" << endl;
    }
  }

  os << "}";
  return os;
}

void test_pprint() {
  for(unsigned char t = 0; t < 128; ++t) {
    cout << int(t) << ") " << endl;
    pprint(cout, t) << endl << endl;
  }
}

void test_graph() {
  print_graph(cout);
}

int main() {
  test_graph();
}
