#include<iostream>
#include <string>
#include "clock.h"
using namespace std;

int main(){
  clock_t t1,t2;
  t1 = clock();
  int i,j,k,n = 100;
  int sum = 0;
  for(i = 0; i<n; i++)
  for(j = 0; j<i * i; j++)
  for(k = 0; k<j; k++)
  sum++;
  t2 = clock();
  double diff((double)t2-(double)t1);
  double seconds = diff/CLOCKS_PER_SEC;
  cout << "For n = "<< n<<"time taken is"<<seconds<<"seconds"<<endl;
  return 0;
}
