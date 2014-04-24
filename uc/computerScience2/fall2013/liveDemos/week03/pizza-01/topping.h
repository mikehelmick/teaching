
#include <string>

using namespace std;

/**
 * Represents a single pizza topping
 * @author Mike Helmick, mike.helmick@uc.edu
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
  const string getName();

  /**
   * @return false if this is a standard topping, true if premium
   */
  bool isPremium();
  
private:
  //

};
