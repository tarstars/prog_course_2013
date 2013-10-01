
#pragma once
#include<iostream>

using namespace std;

class Matrix{
 private:
  int colums;
  int lines;
  int **matr;
 public:
  Matrix(int a, int b);
  ~Matrix();
  Matrix(const Matrix &r);
  void print();
  void put();
  void Set(int a, int b, double c);
  double Get(int a, int b);
};

 
