#include "restaurantg.h"
#include <string>
using namespace std;
  RestaurantG::RestaurantG(){
    for(int i = 0; i < 5; i++){
        CustomerRating[i]=0;
    }
  }
  RestaurantG::RestaurantG(string s1, string s2) {
    Name = s1;
    Cuisine = s2;
    for(int i = 0; i < 5; i++){
        CustomerRating[i] = 0;
    }
  }
  void RestaurantG::addCustomerRating(int num){
    if (num > 0 && num < 6){
      CustomerRating[num - 1] += 1;
    }
// precondition :
// postcondition: The function should verify that the parameter num is between 1 and 5, and if so, increment the number of customers rating the restaurant that match the input pa- rameter.
  }
  void RestaurantG::setCuisine(string newCuisine){
    Cuisine = newCuisine;
// precondition : Create a parameter Cuisine
// postcondition: sets the Cuisine of the RestaurantG object to parameter newCuisine
}
  string RestaurantG::getCuisine(){
    return  Cuisine;
  // precondition : It needs the vairable Cuisine set by the function setCuisine
  // postcondition : Returns the Cuisine of the restaurantG object
}
  void RestaurantG::setName(string newName){
    Name = newName;
// precondition : Create a parameter Name
// postcondition: sets the name of the RestaurantG object to parameter Newname
  }
  string RestaurantG::getName(){
    return Name;
// precondition : It needs the vairable Name set by the function setName
// postcondition : Returns the name of the restaurantG object
  }
  float RestaurantG::getAverage(){
    float Sum = (CustomerRating[0]*1)+(CustomerRating[1]*2)+(CustomerRating[2]*0)+(CustomerRating[3])*1+(CustomerRating[4]*1);
    float num_stars = CustomerRating[0]+CustomerRating[1]+CustomerRating[2]+CustomerRating[3]+CustomerRating[4];
    float ave = Sum/num_stars;
    return ave;
// precondition : Must first understant and create the addCustomerRating function.
// postcondition : Returns the average customer rating of a restaurant.

  }
