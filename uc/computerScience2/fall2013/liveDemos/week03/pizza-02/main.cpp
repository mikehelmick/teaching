
#include "topping.h"
#include <vector>
#include <iostream>

using namespace std;

/**
 * program to create pizza toppings
 */
int main() {
  topping pepperoni("pepperoni", false);
  topping cheese("cheese", false);
  topping extra_cheese("extra cheese", true);

  vector<topping> myToppins;
  myToppins.push_back(pepperoni);
  myToppins.push_back(cheese);
  myToppins.push_back(extra_cheese);

  cout << "Topping #1 is " << myToppins[1].getName() << " premium? "
      << myToppins[1].isPremium() << endl;
}