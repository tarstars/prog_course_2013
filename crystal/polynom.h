#pragma once
#include<iostream>
#include<vector>
class Polynom{
  double w,x, y, z; // w coeffecient at a^3, x at a^2, y at a^1, z at a^0;
  public:
 Polynom(): w(0), x(0),y(0),z(0){}
 Polynom(double ww,double xx, double yy, double zz) : w(ww), x(xx),y(yy), z(zz){}
  friend std:: ostream& operator<<(std::ostream&, const Polynom&);
  void set(double ww,double xx, double yy, double zz);
  std::vector<double> solvePolynom();// solve cubic equation if all roots are real; 
};
