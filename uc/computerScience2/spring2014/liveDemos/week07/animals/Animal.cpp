#include <Animal.h>

Animal::Animal() {
  cout << "Animal constructor called" << endl;
}

Animal::~Animal() {
  cout << "Animal destructor called" << endl;
}

void Animal::printName() {
  cout << "animal" << endl;
}

int Animal::getAge() {
  return age;
}

void Animal::setAge(int age) {
  this->age = age;
}

