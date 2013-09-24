#pragma once

#include <iostream>
#include "solvable.h"

class circlewalk : public Solvable{
	double x, y;
public:
	circlewalk();
	circlewalk(double xx, double yy);
	friend std::ostream& operator<<(std::ostream&, const circlewalk&);
	circlewalk operator*(double) const; // не будет изменять объект, к которому применяется
	circlewalk operator+(const circlewalk& r) const; 
	circlewalk deriv(double) const;
	
	Solvable* mult(double);
	Solvable* add(Solvable*);
	Solvable* derive();
	Solvable* clone();
	void print(std::ostream&);
};