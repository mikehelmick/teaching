#include <Parrot.h>

Parrot::Parrot() {
  cout << "Parrot constructor called" << endl;
}

Parrot::~Parrot() {
  cout << "Parrot destructor called" << endl;
}

void Parrot::printName() {
  cout << "parrot" << endl;
}

bool Parrot::canTalk() {
  return true;
}

