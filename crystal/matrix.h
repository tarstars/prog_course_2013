#pragma once
#include<iostream>

using namespace std;

class Matrix{
 private:
  int columns;
  int lines;
  int **matr;
 public:
  Matrix(int a, int b);
  ~Matrix();
  Matrix(const Matrix &r);
  void print() const;
  void put();
  void Set(int a, int b, double c);
  double Get(int a, int b) const;
  double trace() const;
  Matrix operator*(const Matrix&) const;
  double det() const;
};

 
