#include <iostream>
#include "date.h"
using namespace std;

 Date::Date(int d, int m, int y)
  { if ((1 <= d && d <= 31) && (1 <= m && m <= 12)){
       day = d; month = m; year = y;}
    else{
      cerr << "Incorrect data for Date type: Date is set to 0/0/0" << endl;
      day = month = year = 0;
    }
  }

 void Date::printDate()
  { cout << " " << day << "/" << month << "/" << year << endl;
  }


