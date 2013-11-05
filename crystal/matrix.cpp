#include "matrix.h"
#include "vec3.h" 

#include <iostream>

using namespace std;

Matrix::Matrix(int a, int b){
  lines = a;
  columns = b;
  matr = new double *[lines];
  for(int i = 0; i < lines; ++i){
    matr[i] = new double [columns];
  }
  
  for(int p = 0; p < lines; p++) {
    for(int q = 0; q < columns; q++) {
      matr[p][q] = 0;
    }
  }
  
  return;
}

Matrix::~Matrix(){
  for(int i = 0; i < lines; ++i){
    delete[] matr[i];
  }
  delete[] matr;
}

void Matrix:: put(){
  cout << "Enter the matrix's elements" << endl;
  for (int i = 0; i < lines; ++i){
    for (int j = 0; j < columns; ++j){
      cout << "c[" << i <<"][" << j <<"] =";
      cin >> matr[i][j];
      cout << endl;
    }
  }
}
void Matrix::print() const {
  for(int i = 0; i < lines; ++i){
    for(int j = 0; j < columns; ++j){
      cout << matr [i][j] << " ";
    }
    cout << endl;
  }
}

Matrix::Matrix(const Matrix &r){
  columns = r.columns;
  lines = r.lines;
  matr = new double *[lines];
  for(int i = 0; i < lines; ++i){
    matr[i] = new double [columns];
    for(int j = 0; j < columns; ++j){
      matr[i][j]= r.matr[i][j];
    }
				    
  }
}

void Matrix::Set(int a, int b, double c ){
  matr[a][b] = c;
}

double Matrix::Get(int a, int b) const{
  return matr [a][b];
}

double Matrix::trace() const{
  double ret = 0;

  if (lines != columns) {
    throw("Matrix::trace for nonsquare matrix");
  }

  for(int p = 0; p < lines; ++p) {
    ret += matr[p][p];
  }
  return ret;
}

Matrix Matrix::operator*(const Matrix& b) const{
  Matrix c(lines, b.columns); 
  for(int i = 0; i < lines; ++i){
    for (int j = 0; j < columns; ++j){
      c[i][j] = 0;
      for (int k = 0; k < lines; ++k){
	c[i][j] += matr[i][k]*b[k][j];
      }
    }
  }
  return c;
}

double Matrix::det() const{ 
double det = 0;
  det =  matr[0][0]*(matr[1][1]*matr[2][2]- matr[1][2]*matr[2][1])- matr[0][1]*(matr[1][0]*matr[2][2]- matr[2][0]*matr[1][2])+ matr[0][2]*(matr[1][0]*matr[2][1]- matr[2][0]*matr[1][1]);
  
return det;
}

Matrix& 
Matrix::operator=(const Matrix& r) {
  if (this == &r) {
    return *this;
  }

  Matrix tmp(r);
  swap(tmp.matr, matr);
  swap(tmp.lines, lines);
  swap(tmp.columns, columns);

  return *this;
}

Vec3 
Matrix::operator*(const Vec3& v) const {
  return Vec3(matr[0][0]*v.at(0)+matr[0][1]*v.at(1)+matr[0][2]*v.at(2),
              matr[1][0]*v.at(0)+matr[1][1]*v.at(1)+matr[1][2]*v.at(2),
              matr[2][0]*v.at(0)+matr[2][1]*v.at(1)+matr[2][2]*v.at(2));
}
