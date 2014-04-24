#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Topping {
public:
  Topping(const string& name) {
    cout << "Topping(" << name << ")" << endl;
    this->name = new string(name);
  }

  // Copy constructor
  Topping(const Topping &that) {
    cout << "copy Topping(" << &that << ")" << endl;
    this->name = new string(*that.name);
  }

  virtual ~Topping() {
    delete name;
  }

  void inspect() {
    cout << "  Topping &=" << this << "  name=" << *name << endl;
  }

private:
  string* name;
};

class Pizza {
public:
  Pizza() {
    toppings = new vector<Topping*>();
  }

  Pizza(const Pizza &that) {
    // WRONG - creats a new vector, but vector copy constructor
    //       - just copies the pointer values. not a deep copy.
    //this->toppings = new vector<Topping*>(*that.toppings);
    
    this->toppings = new vector<Topping*>();
    for (int i = 0; i < that.toppings->size(); i++) {
      this->toppings->push_back(
          new Topping(*(that.toppings->at(i))));
    }
  }

  void addTopping(Topping* topping) {
    toppings->push_back(topping);
  }

  void inspect() {
    cout << "Pizza &= " << this << " toppings=" << toppings->size() << endl;
    for (int i = 0; i < toppings->size(); i++) {
      toppings->at(i)->inspect();
    }
  }

  virtual ~Pizza() {
    for (int i = 0; i < toppings->size(); i++) {
      delete toppings->at(i);
    }
    toppings->clear();
    delete toppings;
  }

private:
  vector<Topping*>* toppings;
};

int main() {
  Pizza a;
  a.addTopping(new Topping("A"));
  a.addTopping(new Topping("B"));
  a.inspect();

  Pizza b(a);
  b.inspect();



}
