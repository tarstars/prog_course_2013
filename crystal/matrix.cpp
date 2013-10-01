#include<iostream>
#include"matrix.h"

using namespace std;

Matrix::Matrix(int a, int b){
  lines = a;
  colums = b;
  matr = new int *[lines];
  for(int i = 0; i < lines; ++i){
    matr[i] = new int [colums];
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
    for (int j = 0; j < colums; ++j){
      cout << "c[" << i <<"][" << j <<"] =";
      cin >> matr[i][j];
      cout << endl;
    }
  }
}
void Matrix::print(){
  for(int i = 0; i < lines; ++i){
    for(int j = 0; j < colums; ++j){
      cout << matr [i][j] << " ";
     
    }
    cout << endl;
  }
}

Matrix::Matrix(const Matrix &r){
  colums = r.colums;
  lines = r.lines;
  matr = new int *[lines];
  for(int i = 0; i < lines; ++i){
    matr[i] = new int [colums];
    for(int j = 0; j < colums; ++j){
      matr[i][j]= r.matr[i][j];
    }
				    
  }
}

void Matrix::Set(int a, int b, double c ){
  matr[a][b] = c;
}

double Matrix::Get(int a, int b){
  return matr [a][b];
}
