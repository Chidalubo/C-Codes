#include <iostream>
#include <vector>
#include <string>
#include "Matrix.h"
/*
template <class T>

void readFile(vector<T> & a,int *len, int &row,int &ncol,const string data){
  ifstream input(data);
  if(input.is_open()){
    input>>nrow>>ncol>>len;
    a.resize(len);
    for(int a=0; a<len;a++){
      input>>a[i];
    }
  }
  input.close();
};

template <class T>
void writeToFile(vector<T> & a,int *len, int nrow,int ncol,const string data ){
ofstream outdata(data);
if(outdata.is_open()){
outdata<<nrow<<" "<<ncol << " "<<len<<endl;
for(int l=0; l<len ;l++){
int y=0;
if(y<9)
{
outdata<<a[l]<<" ";
y++;
}
else{
outdata<<a[l]<<endl;
y=0;
}
}
}
};

*/
int main(){

int r = 3, c = 3;
//double d =0.0;
vector<double> v2;
vector<double> v3;
v2 = {1,12,3,4,9,6,2,6,5};
Matrix m(r,c,v2);
Matrix mb(r,c,v2);
Matrix m3(r,c);

cout << mb << endl;
cout << mb(2,2) << endl;
cout << endl;

cout << "this is the += Opperator" << endl;
cout << endl;
cout << "m" << endl;
cout << m << endl;
cout << "mb" << endl;
cout << mb << endl;
cout << "mb+=m" << endl;
cout << (mb+=m) << endl;

cout << "this is the -= Opperator" << endl;
cout << endl;
cout << "m" << endl;
cout << m << endl;
cout << "mb" << endl;
cout << m << endl;
cout << "mb-=m" << endl;
cout << (mb-=m) << endl;

cout << "this is the *= Opperator" << endl;
cout << endl;
cout << "m" << endl;
cout << m << endl;
cout << "mb" << endl;
cout << m << endl;
cout << "mb*=m" << endl;
cout << (mb*=m) << endl;

cout << "this is the default constructor" << endl;
cout << endl;
cout << "m3" << endl;
cout << m3 << endl;

m.~Matrix();
mb.~Matrix();
m3.~Matrix();
return 0;
}
