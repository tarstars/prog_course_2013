#include "robot.h"

using namespace std;

Robot::Robot() : x(3), y(3) {

}

ostream& 
operator<<(ostream &os, const Robot &r) {
  return os << r.x << ", " << r.y;
}

void
Robot::right() {
  ++x;
}

void
Robot::up() {
  ++y;
}

void
Robot::down() {
  --y;
}

void
Robot::left() {
  --x;
}
