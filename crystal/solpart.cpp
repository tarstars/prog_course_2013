#include "solpart.h"

std::ostream& operator<<(std::ostream& os, const SolPart& r) {
  return os << "v = " << r.v << " q = " << r.q;
}
