#include "SolPart.h"
#include <iostream>

using namespace std;

ostream& operator<<(ostream& os,const SolPart& sol) {
    return os << sol.v << endl << sol.q;
}
