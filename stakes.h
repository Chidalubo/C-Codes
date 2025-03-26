#include <iostream>
#include <string>
using namespace std;

class mediumStakes
{
public:
  int mediumRandomSpinOneToEight(int min, int max);
  int mediumRandomSpinFourToSeven(int min, int max);
  void setSpinnerChoice(int c);
  int getSpinnerChoice();
  int addSpinNum();
  //int getSpinScore();
  int getCalculatedCredit();
private:
  int spinNum = 0;
  int choice;
  int buyIn;
  int initialCredit = 100;
  int currentCredit = initialCredit;
  int spinnerChoice;
};

class lowerStakes
{
  int mediumRandomSpinOneToEight(int min, int max);
  int mediumRandomSpinFourToSeven(int min, int max);
  void setSpinnerChoice(int c);
  int getSpinnerChoice();
  int addSpinNum();
  //int getSpinScore();
  int getCalculatedCredit();
private:
  int spinNum = 0;
  int choice;
  int buyIn;
  int initialCredit = 100;
  int currentCredit = initialCredit;
  int spinnerChoice;

};

class higherStakes
{
  int mediumRandomSpinOneToEight(int min, int max);
  int mediumRandomSpinFourToSeven(int min, int max);
  void setSpinnerChoice(int c);
  int getSpinnerChoice();
  int addSpinNum();
  //int getSpinScore();
  int getCalculatedCredit();
private:
  int spinNum = 0;
  int choice;
  int buyIn;
  int initialCredit = 100;
  int currentCredit = initialCredit;
  int spinnerChoice;
};
