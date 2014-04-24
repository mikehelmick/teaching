// #ifndef TOPPING_H
// #define TOPPING_H

#include <string>

using namespace std;

/**
 * Represents a single pizza topping
 */
class Topping {

public:
  /**
   * Creates a new pizza topping;
   */
  Topping(string name, bool isPremium);

  /**
   * @return the name of the pizza topping
   */
  string getName();

  /**
   * @return false if this is a standard topping, true if premium
   */
  bool isPremium();
  
private:
  // Implementation
};

// #endif