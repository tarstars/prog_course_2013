#include<iostream>
#include"matrix.h"

using namespace std;

Matrix::Matrix() {
    lines = 3;
    columns = 3;
    matr = new double *[lines];
    for(int i = 0; i < lines; ++i){
        matr[i] = new double [columns];
    }

    for(int p = 0; p < lines; p++) {
        for(int q = 0; q < columns; q++) {
            matr[p][q] = 0;
        }
    }
}

Matrix::Matrix(int a, int b) {
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
}

Matrix::~Matrix(){
    for(int i = 0; i < lines; ++i){
        delete[] matr[i];
    }
    delete[] matr;
}

void
Matrix:: put(){
    cout << "Enter the matrix's elements" << endl;
    for (int i = 0; i < lines; ++i){
        for (int j = 0; j < columns; ++j){
            cout << "c[" << i <<"][" << j <<"] =";
            cin >> matr[i][j];
            cout << endl;
        }
    }
}

void
Matrix::print() const {
    for(int i = 0; i < lines; ++i){
        for(int j = 0; j < columns; ++j){
            cout << matr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
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

void
Matrix::Set(int a, int b, double c ){
    matr[a][b] = c;
}

double
Matrix::Get(int a, int b) const{
    return matr[a][b];
}

double
Matrix::trace() const{
    if (lines != columns) {
        throw("Matrix::trace for nonsquare matrix");
    }

    double ret = 0;
    for(int p = 0; p < lines; ++p) {
        ret += matr[p][p];
    }
    return ret;
}

Matrix
Matrix::operator*(const Matrix& B_mat) const{
    Matrix product(3,3);
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            double res = 0;
            for (int inner = 0; inner < 3; ++inner) {
                res += matr[row][inner] * B_mat.Get(inner,col);
            }
            product.Set(row,col,res);
        }
    }
    return product;
}

Matrix&
Matrix::operator=(const Matrix& r) {
    if(this == &r) {
        return *this;
    }
    Matrix tmp(r); //copy-constructor
    swap(tmp.matr, matr);
    swap(tmp.lines, lines);
    swap(tmp.columns, columns);
    return *this;
}

double
Matrix::det() const{
    return + matr[0][0]*(matr[1][1]*matr[2][2] - matr[2][1]*matr[1][2])
           - matr[0][1]*(matr[1][0]*matr[2][2] - matr[2][0]*matr[1][2])
           + matr[0][2]*(matr[1][0]*matr[2][1] - matr[2][0]*matr[1][1]);
}
