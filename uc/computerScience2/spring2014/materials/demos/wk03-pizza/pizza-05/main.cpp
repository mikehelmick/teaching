
#include "topping.h"
#include "pizza.h"
#include <vector>
#include <iostream>

using namespace std;

/**
 * program to create pizza toppings
 */
int main() {
  Topping pepperoni("pepperoni", false);
  Topping cheese("cheese");
  Topping extra_cheese("extra cheese", true);

  // No () for default constructor - weird, I know.
  Pizza pizza;
  pizza.addTopping(pepperoni);
  pizza.addTopping(extra_cheese);

  cout << "My pizza has " << pizza.getToppingsCount() << " toppings." << endl;
  vector<Topping> toppings = pizza.getToppings();
  for (vector<Topping>::iterator iter = toppings.begin(); iter != toppings.end(); iter++) {
    cout << "  + " << iter->getName() << endl;
  }
  cout << "The final price is $" << pizza.getPrice() << endl;
}