#pragma once

#include <iostream>

class Solvable {
public:
	virtual Solvable* mult(double) = 0;
	virtual Solvable* add(Solvable*) = 0;
	virtual Solvable* derive() = 0;
	virtual Solvable* clone() = 0;
	virtual void print(std::ostream&) = 0;
	
	virtual ~Solvable(){}
};