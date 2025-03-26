#include "Matrix.h"
#include <string>
#include <vector>
using namespace std;
Matrix::Matrix(int r, int c, double d){
  rows = r;
  cols = c;
  element = new dobule[r*c];
  for(int i = 0; i < r*c; i++){
    element[i] = d;
  }
};
Matrix::Matrix(const Matrix& m){
  rows = m.rows;
  cols = m.cols;
  element = new dobule[m.rows*m.cols];
  for(int i = 0; i < r*c; i++){
    element[i] = m.element[i];
  }
};
Matrix::Matrix(int r, int n, vector<double> v){
  rows = r;
  cols = n;
  element = new dobule[r*n];
  for(int i = 0; i < r*n; i++){
    element[i] = v[i];
  }
};
Matrix::Matrix(){
  delete [] element;
}
const double Matrix::operator()(int i, int j)const {
  return element[(i - 1) * cols + (j-1)];
}
Matrix& Matrix::operator=(const Matrix& m){
  ~Matrix();
  rows = m.rows;
  cols = m.cols;
  element = new double[m.rows*m.cols];
  for(int i = 0; i < m.rows*m.cols; i++){
    element[i] = m.element[i];
  }
  return *this;
};
Matrix& Matrix::operator += (const Matrix& x){
  if (rows == x.rows && cols == x.cols){
    for (int i = 0; i < rows*cols; i++) {
      element[i] += x.element[i];
    }
  }
  return *this;
};
Matrix& Matrix:: operator -= (const Matrix& x){
  if (rows == x.rows && cols == x.cols){
    for(int i = 0; i < rows*cols; i++){
      element[i] -= x.element[i];
    }
  }
  return *this;
};
Matrix& Matrix:: operator *= (double d){
  if (rows == d.rows && cols == d.cols){
    for (int i = 0; i < rows*cols; i++) {
      element[i] = element[i] * d;
    }
  }
  return *this;
};
Matrix& Matrix:: operator *= (const Matrix& m){
  if(cols == m.rows){
    Matrix e(rows, m.cols, 0.0);
    for(int i = 0; i < rows; i++){
      for(int j = 0; j < m.cols; j++){
        for(int z = 0; z < cols; z++){
          e.element[(i) * cols + (j)] += element[i*cols+j]*m.element[z*m.cols+j];
        }
      }
    }
    for(int i = 0; i < (rows*m.cols); i++){
      element[i] = e.element[i];
    }
  }
  return *this;
};
Matrix operator+(const Matrix& 1, const Matrix&r){
  Matrix a1(r);
  return (a1 += 1);
};
Matrix operator-(const Matrix& 1, const Matrix&r){
  Matrix a1(r);
  return (a1 -= 1);
};
Matrix operator*(const Matrix& 1, const Matrix&r){
  Matrix a1(r);
  return (a1 *= 1);
};
Matrix operator*(double d, const Matrix& r){
  Matrix a1(r);
  return (a1 *= 1);
};
Matrix operator+(const Matrix& m, double d){
  Matrix a1(r);
  return (a1 *= 1);
};
void Matrix :: print(ostream& sout) const{
  for(int i = 0; i < rows; i++){
    for(int w = 0; w < cols; w++){
      sout << element[i = cols + 1] << " ";
    }
    sout << endl;
  }
};
ostream& operator <<(ostream& out, const Matrix& x){
  x.print(out);
  return out;
};
