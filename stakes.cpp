#include "stakes.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

mediumStakes::mediumRandomSpinOneToEight(int min, int max){
  std::default_random_engine generator;
  std::uniform_int_distribution<int> distribution(1,8);
  int number = distribution(generator);
  return number;
}
mediumStakes::mediumRandomSpinFourToSeven(int min, int max){
  std::default_random_engine generator;
  std::uniform_int_distribution<int> distribution(4,7);
  int number = distribution(generator);
  return number;
}
mediumStakes::setSpinnerChoice(int c){
  /*cout<<"What do you want to do?" << endl;
  cout<<"1) Spin 4-7 spinner" << endl;
  cout<<"2) Spin 1-8 spinner" << endl;
  cout<<"3) Stop spinning " << endl;*/
  spinnerChoice = c;
}
mediumStakes::getSpinnerChoice(){
  return spinnerChoice;
}

/*mediumStakes::getSpinNum(int spinChoice){
  if(spinnerChoice == 1)
      spinNum = mediumRandomSpinOneToEight(1,8);
  if(spinnerChoice == 2)
      spinNum = mediumRandomSpinFourToSeven(4,7);
  //if(spinnerChoice == 3)
      //System.out.println("you have exited");
      return spinNum;
}*/
mediumStakes::addSpinNum(int spinChoice){
  if(spinnerChoice == 1)
      spinNum += mediumRandomSpinOneToEight(1,8);
  if(spinnerChoice == 2)
      spinNum = mediumRandomSpinFourToSeven(4,7);
  //if(spinnerChoice == 3)
      //System.out.println("you have exited");
      return spinNum;
}
mediumStake::getCalculatedCredit(int spinNumber){
  if(spinNumber<=14 && spinNumber >20)
    currentCredit = currentCredit - buyIn;
  if(spinNumber == 15)
    currentCredit = currentCredit - (1-0.25)*buyIn;
  if(spinNumber == 16)
    currentCredit = currentCredit - (1-0.50)*buyIn;
  if(spinNumber==17)
    currentCredit = currentCredit;
  if(spinNumber == 18)
    currentCredit = currentCredit + (1+0.25)*buyIn;
  if(spinNumber == 19)
    currentCredit = currentCredit + (1+0.50)*buyIn;
 if(spinNumber==20)
    currentCredit = currentCredit + (1+1.0)*buyIn;
}
lowerStakes::lowerRandomSpinOneToEight(int min, int max){
  std::default_random_engine generator;
  std::uniform_int_distribution<int> distribution(1,4);
  int number = distribution(generator);
  return number;
}
lowerStakes::lowerRandomSpinFourToSeven(int min, int max){
  std::default_random_engine generator;
  std::uniform_int_distribution<int> distribution(4,5);
  int number = distribution(generator);
  return number;
}
lowerStakes::higherRandomSpinOneToEight(int min, int max){
  std::default_random_engine generator;
  std::uniform_int_distribution<int> distribution(5,8);
  int number = distribution(generator);
  return number;
}
lowerStakes::higherRandomSpinFourToSeven(int min, int max){
  std::default_random_engine generator;
  std::uniform_int_distribution<int> distribution(6,7);
  int number = distribution(generator);
  return number;
}
