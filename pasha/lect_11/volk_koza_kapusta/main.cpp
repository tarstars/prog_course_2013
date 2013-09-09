#include <iostream>
#include <vector>

using namespace std;

//	./prog.exe | dot -o a.png -Tpng  (плохо)
//	./prog.exe | fdp -o a.png -Tpng

// c = 	{_ _ _ *  m aa ab bb} = {_ _ _ лодка Человек волк коза капуста}
//		{      4  3  2  1  0}

bool gb(unsigned char c, int ind) {
	return (c & (1 << ind)) != 0;	//true => оъект с индексом ind нах-ся справа
									//1<<ind сдвиг на ind разрядов влево от первого
}

ostream& pprint(ostream &os, unsigned char c, string del) {
	os << int(c) << del; //номер состояния
	os << (gb(c, 4) ? "  |* " : " *|  ") << del; //лодка
	os << (gb(c, 3) ? "  |m " : " m|  ") << del; //человек
	os << (gb(c, 2) ? "  |aa" : "aa|  ") << del;	//волк
	os << (gb(c, 1) ? "  |ab" : "ab|  ") << del;	//коза
	os << (gb(c, 0) ? "  |bb" : "bb|  ") << del; //капуста
	//if db==true => "  |* "; else " *|  "
	return os;
}

bool valid_state(unsigned char b) {
	//{      4  3  2  1  0}
	//{_ _ _ *  m aa ab bb}
	
	bool man = gb(b, 3); //где нах-ся человек
	bool boat = gb(b, 4); //где нах-ся лодка
	if(man != boat) {
		return false;
	}
	for(int t = 0; t <= 2; ++t) {
		bool ob = gb(b, t); //где нах-ся объект
		if (ob != man) { //объект и чел-к на разных берегах
			if((t == 0) && (ob == gb(b, 1))) {
				return false;
			}
			if((t == 1) && (ob == gb(b, 0)) && (ob == gb(b, 2))) {
				return false;
			}
			if((t == 2) && (ob == gb(b, 1))) {
				return false;
			}
		}
	}
	return true;
}

bool can_go(unsigned char a, unsigned char b) {
	//{      4  3  2  1  0}
	//{_ _ _ *  m aa ab bb}
	
	if (!valid_state(b)) {
		return false; //нельзя переместиться в неверное состояние
	}
	
	bool boat_a = gb(a, 4);
	bool boat_b = gb(b, 4);
	bool man_a = gb(a, 4);
	bool man_b = gb(b, 4);
	if ((boat_a == boat_b) || (man_a == man_b) || (man_a != boat_a)) {
		return false; //лодка и человек перемещаются вместе
	}
	
	int s = 0; 
	for(int t = 0; t <= 2; ++t) {
		bool pa = gb(a, t);
		bool pb = gb(b, t);
		if (pa != pb) { //объект должен переместиться
			if (pa != boat_a) {
				return false;
			}
			++s;
		}
	}
	if (s > 1) {
		return false; //можно перевезти не более одного объекта
	}
	
	return true;
}

ostream&
print_graph(ostream& os) {
	os << "graph t {" << endl;
	for(unsigned char a = 0; a < 32; ++a) { //2^5=32 - всего состояний
		for(unsigned char b = 0; b < a; ++b) {
			if (valid_state(a) && valid_state(b) && can_go(a, b)) {
				os << int(a) << "--" << int(b) << ";" << endl;
			}
		}
	}
  
	for(unsigned char t = 0; t < 32; ++t) {
		if (valid_state(t)) {
			os << int(t) << "[label = \"";
			pprint(os, t , "\\n") << "\"];" << endl;
		}	
	}

	os << "}";
	return os;
}

void solve() {
	int n = 32;
	vector<int> dat(n, -1);
	dat[0] = 0; //исходное положение
	bool todo = true;
	while(todo) {
		todo = false;
		for(int p=0; p<n; ++p) {
			if(dat[p] != -1) {
				for(int q=0; q<n; ++q) {
					if(p != q && dat[q] == -1 && can_go(p,q)) {
						dat[q] = p; // откуда сюда пришли
						todo = true;
					}
				}
			}
		}
	}
	int p = n - 1;
	while(p != 0) {
		p = dat[p];
		cout << p <<endl;
		pprint(cout, p, "\n") << endl << endl;
	}
}

void test_pprint() {
	for(unsigned char t = 0; t < 32; ++t) {
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

int main() {
	//test_pprint();
	test_graph();
	//test_solve();
}
