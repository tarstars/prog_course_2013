#include "Tensor4.h"

using namespace std;

ostream& operator <<(ostream& os, const Tensor4& t) {
	os << scientific;
	os.precision(2);
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			os << t.at(i, j, 0, 0) << ' ' << t.at(i, j, 0, 1) << ' ' << t.at(i, j, 0, 2) << "   ";
		}
		os << endl;
		for(int j = 0; j < 3; j++) {
			os << t.at(i, j, 1, 0) << ' ' << t.at(i, j, 1, 1) << ' ' << t.at(i, j, 1, 2) << "   ";
		}
		os << endl;
		for(int j = 0; j < 3; j++) {
			os << t.at(i, j, 2, 0) << ' ' << t.at(i, j, 2, 1) << ' ' << t.at(i, j, 2, 2) << "   ";
		}
		os << endl << endl;
	}
	return os;
}