#ifndef _ROBOT_
#define _ROBOT_

#include <iostream>

class Robot {
  int x, y;
public:
  Robot();
  
  void right();
  void left();
  void up();
  void down();

  friend std::ostream& operator<<(std::ostream&, const Robot&);
};


#endif
