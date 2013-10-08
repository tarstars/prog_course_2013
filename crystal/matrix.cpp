#include<iostream>
#include"matrix.h"

using namespace std;

Matrix::Matrix(int a, int b){
  lines = a;
  columns = b;
  matr = new int *[lines];
  for(int i = 0; i < lines; ++i){
    matr[i] = new int [columns];
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
  matr = new int *[lines];
  for(int i = 0; i < lines; ++i){
    matr[i] = new int [columns];
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

Matrix Matrix::operator*(const Matrix& mat) const{
  return mat;
}

double Matrix::det() const{
  return 1;
}
