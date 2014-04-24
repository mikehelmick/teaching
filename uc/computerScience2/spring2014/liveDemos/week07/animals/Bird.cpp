#include <Bird.h>

Bird::Bird() {
  cout << "Bird constructor called" << endl;
  cout << "Bird age: " << this->getAge() << endl;
}

Bird::~Bird() {
  cout << "Bird destructor called" << endl;
}

