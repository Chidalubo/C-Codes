#include "restaurantg.h"
#include <iostream>
#include <iomanip>
#include <string>

int main(){
  RestaurantG r1("Sea Palace", "sushi");
  cout << "Restaurant Name: " << r1.getName() << endl;
  cout << "Cuisine Name: " << r1.getCuisine() << endl;
  r1.addCustomerRating(5);
  r1.addCustomerRating(4);
  r1.addCustomerRating(3);
  r1.addCustomerRating(5);
  r1.addCustomerRating(3);
  cout << "Rating Average: " << r1.getAverage() << "\n";


  RestaurantG r2("Burger King", "Burger");
  cout << "Restaurant Name: " << r2.getName() << endl;
  cout << "Cuisine Name: " << r2.getCuisine() << endl;
  r2.addCustomerRating(1);
  r2.addCustomerRating(4);
  r2.addCustomerRating(5);
  r2.addCustomerRating(3);
  r2.addCustomerRating(2);
  cout << "Rating Average: " << r2.getAverage() << "\n";


  RestaurantG r3("Pizza 73", "BBQ Chicken Pizza");
  cout << "Restaurant Name: " << r3.getName() << endl;
  cout << "Cuisine Name: " << r3.getCuisine() << endl;
  r3.addCustomerRating(1);
  r3.addCustomerRating(3);
  r3.addCustomerRating(4);
  r3.addCustomerRating(4);
  r3.addCustomerRating(4);
  cout << "Rating Average: " << r3.getAverage() << "\n";

  RestaurantG r4("MC Donald", "Big Mac");
  cout << "Restaurant Name: " << r4.getName() << endl;
  cout << "Cuisine Name: " << r4.getCuisine() << endl;
  r4.addCustomerRating(1);
  r4.addCustomerRating(2);
  r4.addCustomerRating(5);
  r4.addCustomerRating(3);
  r4.addCustomerRating(2);
  cout << "Rating Average: " << r4.getAverage() << "\n";

    RestaurantG r5("Dairy Queen", "Chips and Chicken");
    cout << "Restaurant Name: " << r5.getName() << endl;
    cout << "Cuisine Name: " << r5.getCuisine() << endl;
    r5.addCustomerRating(1);
    r5.addCustomerRating(3);
    r5.addCustomerRating(3);
    r5.addCustomerRating(4);
    r5.addCustomerRating(5);
    cout << "Rating Average: " << r5.getAverage() << "\n";

    RestaurantG r6("KFC", "Chicken bucket");
    cout << "Restaurant Name: " << r6.getName() << endl;
    cout << "Cuisine Name: " << r6.getCuisine() << endl;
    r6.addCustomerRating(1);
    r6.addCustomerRating(4);
    r6.addCustomerRating(5);
    r6.addCustomerRating(3);
    r6.addCustomerRating(2);
    cout << "Rating Average: " << r6.getAverage() << "\n";

    RestaurantG r7("Taco Bell", "Value Box");
    cout << "Restaurant Name: " << r7.getName() << endl;
    cout << "Cuisine Name: " << r7.getCuisine() << endl;
    r7.addCustomerRating(1);
    r7.addCustomerRating(3);
    r7.addCustomerRating(5);
    r7.addCustomerRating(5);
    r7.addCustomerRating(2);
    cout << "Rating Average: " << r7.getAverage() << "\n";

    RestaurantG r8("Pizza Hut", "Large meat lover");
    cout << "Restaurant Name: " << r8.getName() << endl;
    cout << "Cuisine Name: " << r8.getCuisine() << endl;
    r8.addCustomerRating(1);
    r8.addCustomerRating(3);
    r8.addCustomerRating(5);
    r8.addCustomerRating(4);
    r8.addCustomerRating(2);
    cout << "Rating Average: " << r8.getAverage() << "\n";

    RestaurantG r9("Popeyes", "Chicken sandwich");
    cout << "Restaurant Name: " << r9.getName() << endl;
    cout << "Cuisine Name: " << r9.getCuisine() << endl;
    r9.addCustomerRating(1);
    r9.addCustomerRating(4);
    r9.addCustomerRating(5);
    r9.addCustomerRating(4);
    r9.addCustomerRating(3);
    cout << "Rating Average: " << r9.getAverage() << "\n";

    RestaurantG r10("Subway", "Pizza Sub Melt");
    cout << "Restaurant Name: " << r10.getName() << endl;
    cout << "Cuisine Name: " << r10.getCuisine() << endl;
    r10.addCustomerRating(2);
    r10.addCustomerRating(1);
    r10.addCustomerRating(5);
    r10.addCustomerRating(5);
    r10.addCustomerRating(2);
    cout << "Rating Average: " << r10.getAverage() << "\n";
}
