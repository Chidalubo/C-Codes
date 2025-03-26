#include <iostream>
#include <string>
using namespace std;

class RestaurantG
{
public:
  RestaurantG();
  RestaurantG(string s1, string s2);
  void addCustomerRating(int num);
  void setCuisine(string newCuisine);
  string getCuisine();
  void setName(string newName);
  string getName();
  float getAverage();
private:
  string Name;
  string Cuisine;
  int CustomerRating[5];
};
