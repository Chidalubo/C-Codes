#include<iostream>
#include <vector>
#include <string>
#include "Matrix.h"

using namespace std;

template <class T>
void writeToFile(vector<T> & a, int len, int nrow, const string data){

}
 temeplate <class T>
void ReadFile(vector<T> & a, int len, int nrow, const string data{
  ifstream insert(data);
  if(insert.is_open()){
    input >> nrow
  }
}

int main(){
  int r = 3, c = 3;
  double d = 0.0;
  vector <double> v;
  vec = {11,12,13,14,15,16,17,18,19};

  Matrix a1(r,c,vec);
  Matrix a2(a1);
  Matrix a3(r,c,vec);
  Matrix a4();

  a1 = a1 * a2;

  cout<< a1 << endl;
  cout << a2 << endl;
  cout << a3 << endl;

  return 0;
};
