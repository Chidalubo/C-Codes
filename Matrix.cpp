#include "Matrix.h"
#include <iostream>

Matrix::Matrix (int r, int c, double d){
  rows = r;
  cols = c;
  element = new double[r*c];
  for(int i=0;i<r*c; i++){
    element[i] = d;
  }
}

Matrix::Matrix(const Matrix& m){
  rows = m.rows;
  cols =m.cols;
  element = new double[m.rows*m.cols];
  for(int i=0; i<rows*cols; i++){
    element[i]=m.element[i];
  }
}

Matrix::Matrix(int r,int n,vector<double> v){
  rows =r;
  cols =n;
  element = new double[r*n];
  for(int i=0;i<r*n;i++){
    element[i] =v[i];
  }
}

Matrix::~Matrix(){
  delete [] element;
};

const double& Matrix::operator ()(int i,int j)const {
  return element[i * cols + j];
};

double& Matrix::operator ()(int i,int j){
  return element[i * cols + j];
};

Matrix& Matrix::operator = (const Matrix& m){
  delete [] element;
  rows = m.rows;
  cols = m.cols;
  element = new double[m.rows*m.cols];
  for(int j=0;j<m.rows*m.cols; j++){
    element [j] = m.element[j];
  }
  return *this;
};

Matrix& Matrix::operator += (const Matrix& m){
  if(rows==m.rows && cols ==m.cols){
    for(int t = 0; t < rows*cols; t++){
      element[t] += m.element[t];
    }
  }
  return *this;
};

Matrix& Matrix::operator -= (const Matrix& x){
if(rows==x.rows && cols==x.cols){
  for(int f=0; f<rows*cols; f++){
element [f]-= x.element[f];
  }
}
return *this;
};

Matrix& Matrix:: operator *=(double d){
  for(int y=0; y<rows*cols; y++){
    element[y] *= d;
    }
  return *this;
};

 Matrix& Matrix::operator *=(const  Matrix& m){
   if(cols==m.rows){
     Matrix f(rows,m.cols, 0.0);
     for(int i=0; i<rows; i++){
       for(int h=0; h<m.cols; h++){
         for(int n=0; n<m.cols; n++){
         f.element[(i) *cols + (h)] += element[i*cols+h]*m.element[n*m.cols+h];
       }
     }
   }
   for(int t=0; t<(rows*m.cols); t++){
     element[t]= f.element[t];
   }
 }
 return *this;
};

Matrix operator + (const Matrix& l, const Matrix& r){
  Matrix a1(l);
  a1 += r;
  return a1;
};

Matrix operator - (const Matrix& l, const Matrix& r){
  Matrix a2(l);
  a2 -= r;
  return a2;
};

Matrix operator * (const Matrix& l, const Matrix& r){
  Matrix a3(l);
  a3 *= r;
  return a3;
};

Matrix operator * (double d, const Matrix& r){
  Matrix a4(r);
  a4 *= d;
  return a4;
};

Matrix operator + (const Matrix& m, double d){
  Matrix a5(m);
  a5 += d;
  return a5;
};
 void Matrix::print (ostream& sout)const {
for(int i=0;i<rows;i++){
  for(int j=0; j < cols; j++){
sout<<(*this)(i,j)<<" ";
  }
  sout<<endl;
}
};

ostream& operator <<(ostream& out,const Matrix& x){
  x.print(out);
  return out;
}
