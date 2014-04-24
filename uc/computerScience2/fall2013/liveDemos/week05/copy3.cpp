#include <iostream>
#include <vector>
using namespace std;

class Size {
};

class Topping {
  Topping() {
  }
};

class Pizza {
public:
  Pizza() {
    toppings = new vector<Topping*>();
  }

private:
  vector<Topping*>* toppings;
  Size size;
};

int main() {
}
