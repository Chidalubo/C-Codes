#include<iostream>
#include <string>
using namespace std;

int main(){
  clock_t t1,t2;
  t1 = clock();
  int i, n = 100000;
  int sum = 0;
  for(i =0; i<n; i++)
  sum++;
  t2 = clock();
  double diff((double)t2-(double)t1);
  double seconds = diff/CLOCKS_PER_SEC;
  cout << "For n ="<< n<<"time taken is"<<seconds<<"seconds"<<endl;
  return 0;
}
