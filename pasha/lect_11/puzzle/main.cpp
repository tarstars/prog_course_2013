#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//	./prog.exe | fdp -o a.png -Tpng

bool gb(unsigned char c, int ind) {
	return (c & (1 << ind)) != 0;
}

ostream& pprint(ostream &os, unsigned char c, string del) {
	os << int(c) << del;
	os << (gb(c, 6) ? "  | *" : "* |  ") << del;
	for(int t = 0; t < 3; ++t) {
		string val("  |  ");
		val[gb(c, t) ? 3 : 0] = '1' + t;
		val[gb(c, t + 3) ? 4 : 1] = 'a' + t;
		os << val << del;
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
			pprint(os, t , "\\n") << "\"];" << endl;
		}	
	}

	os << "}";
	return os;
}

void solve() {
int n = 128;
	vector<int> dat(n, -1);
	queue<int> todo_queue;
	todo_queue.push(0);
	while(!todo_queue.empty() && todo_queue.front()!=127) {
		int current = todo_queue.front(); //достаём эл-т КК
		todo_queue.pop(); //выкидываем его из очереди
		for(int q=0; q<n; ++q) {
			if(dat[q] == -1 && can_go(current,q)) {//куда можем перейти из КК и где ещё не были
				dat[q] = current; //пишем окуда сюда попали
				todo_queue.push(q); //дописываем вконец очереди
			}
		}
	}
	int p = 127;
	while(p != 0) {
		p = dat[p];
		cout << p <<endl;
		pprint(cout, p, "\n") << endl << endl;
	}
}

void test_pprint() {
	for(unsigned char t = 0; t < 128; ++t) {
		cout << int(t) << ") " << endl;
		pprint(cout, t, "\n") << endl << endl;
	}
}

void test_graph() {
	print_graph(cout);
}

void test_solve() {
	solve();
}

void test_queue() {
	queue<int> dat;
	for(int t=0; t<10; ++t) {
		dat.push(t);
	}
	while(!dat.empty()) {
		cout << dat.front() << " ";
		dat.pop();
	}
}

int main() {
	//test_queue();
	//test_graph();
	test_solve();
}
