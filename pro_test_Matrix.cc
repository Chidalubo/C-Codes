#include<iostream>
#include <vector>
#include <string>
#include "Matrix.h"

using namespace std;

template <class T>
void writeToFile(vector<T> & a, int len, int nrow, int ncol, const string data){
ofstream output(data);

if(output.is_open()){
  output << nrow <<"  "<< ncol << " " << len << endl;
  for (int i = 0; i < len; i++){
    int j = 0;
    if(j < 9)
    {
      output << a[i] << " ";
      j++
    }
    else{
      output << a[i] << endl;
      j=0;
    }
  }
}
};
 temeplate <class T>
void ReadFile(vector<T> & a, int len, int &row, int &ncol, const string data){
  ifstream input(data);
  if(input.is_open()){
    input >> nrow >> ncol >> len;
    a.resize(len);
    for(int a = 0; a < len; a++){
      input >> a[i];
    }
  }
  input.close();
};

int main(){
  int r = 3, c = 3;
  double d = 0.0;
  double d1 = 2;
  int r1 , c1;
  int ncol1 = 3, nrow = 3, rlen = 9;
  string data = "output.txt";

  vector<double> v;
  vector<double> v1;
  vector<double> vfile;
  v = {11,12,13,14,15,16,17,18,19};
  vfile = {19,18,17,16,15,14,13,12,11};

  writeToFile(vfile, rlen, nrow, ncol1, data);
  ReadFile (v1, rlen, r1, c1, data);

  Matrix mconstruct(r,c,d);
  Matrix const a1(r,c,v);
  Matrix const a2(r1,c1,v1);
  Matrix a3(r,c,d);

  Matrix mcopy(a1);
  Matrix mcopy1(a1);
  Matrix mcopy2(a1);
  Matrix mcopy3(a1);
  Matrix mcopy4(a1);
  Matrix mcopy5(a1);
  Matrix mcopy6(a1);
  Matrix mcopy7(a1);

  Matrix mcopy8(a2);
  Matrix mcopy9(a2);
  Matrix mcopy10(a2);
  Matrix mcopy11(a2);
  Matrix mcopy12(a2);
  Matrix mcopy13(a2);
  Matrix mcopy14(a2);
  Matrix mcopy15(a2);
  Matrix mcopy16(a2);

  Matrix mcopy17(a3);
  Matrix mcopy18(a3);
  Matrix mcopy19(a3);
  Matrix mcopy20(a3);
  Matrix mcopy21(a3);

  cout<< endl;
  cout << a2 << endl;
  cout << a3 << endl;

  return 0;
};
