
#include "topping.h"
#include <vector>
#include <iostream>

using namespace std;

/**
 * program to create pizza toppings
 */
int main() {
  Topping pepperoni("pepperoni", false);
  Topping cheese("cheese", false);
  Topping extra_cheese("extra cheese", true);

  vector<Topping> myToppins;
  myToppins.push_back(pepperoni);
  myToppins.push_back(cheese);
  myToppins.push_back(extra_cheese);

  cout << "Topping #1 is " << myToppins[1].getName() << " premium? "
      << myToppins[1].isPremium() << endl;
}
