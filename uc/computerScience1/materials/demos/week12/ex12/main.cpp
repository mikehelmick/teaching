// ex12 - counter example

#include <iostream>
using namespace std;

class Counter {
public:
  Counter() {
  	cout << "Counter constructor" << endl;
  	count = 0;
  }

  virtual ~Counter() {
  	cout << "Counter destructor" << endl;
  	// nothing to do here
  }

  void increment() {
  	count++;
  }

  int getCount() {
  	return count;
  }

private:
  int count;
};

class Rope {
public:
  Rope() {
  	cout << "Rope constructor" << endl;
    counter = new Counter();
  }

  virtual ~Rope() {
  	cout << "Rope destructor" << endl;
    // need to delete the counter
    delete counter;
  }

  void skip() {
    counter->increment();
  }

  int getSkipCount() {
    return counter->getCount();
  }

private:
	Counter* counter;
};

int main() {
  Rope* jumpRope = new Rope();
  for (int i = 0; i < 10; i++) {
    jumpRope->skip();
    cout << "Skip count: " << jumpRope->getSkipCount() << endl; 
  }

  delete jumpRope;
}
