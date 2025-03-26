#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <vector>
using namespace std;

class Matrix {
public:
  Matrix(int r = 0, int c = 0, double d = 0.0);
  Matrix(const Matrix& m);
  Matrix(int r, int n, vector<double> v);
  Matrix();
  const double& operator()(int i, int j) const;
  double& operator()(int i, int j);
  Matrix& operator=(const Matrix& m);

  Matrix& operator+=(const Matrix& x);
  Matrix& operator-=(const Matrix& x);
  Matrix& operator*=(const Matrix& m);
  Matrix& operator*=(double d);

  void print(ostream& sout) const;
    int ncols() const;
    int nrows() const;
  private:
     int rows;
     int cols;
     double *element;

};
Matrix operator+(const Matrix&1, const Matrix&r);
Matrix operator-(const Matrix&1, const Matrix&r);
Matrix operator*(const Matrix&1, const Matrix&r);
Matrix operator*(double d, const Matrix& r);
Matrix operator+(const Matrix& m, double d);
ostream& operator <<(ostream& out, const Matrix& x);
#endif
