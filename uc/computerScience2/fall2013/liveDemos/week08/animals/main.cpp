#include <Animal.h>
#include <Bird.h>
#include <Parrot.h>

#include <iostream>
using namespace std;

int main() {
  Parrot* p = new Parrot();
  delete p;
}
