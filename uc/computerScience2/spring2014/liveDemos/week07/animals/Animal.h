#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
using namespace std;

class Animal {
public:
  Animal();
  
  virtual ~Animal();

  virtual void printName();

  int getAge();

  void setAge(int age);

private:
  int age;

};

#endif
