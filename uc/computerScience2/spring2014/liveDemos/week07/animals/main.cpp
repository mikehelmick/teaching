#include <iostream>
#include <vector>
using namespace std;

#include <Animal.h>
#include <Bird.h>
#include <Parrot.h>

void printAnimalCharacteristics(Animal* animal) {

}

void printAllAnimals(vector<Animal*> allAnimals) {
  for (int i = 0; i < allAnimals.size(); i++) {
    Animal* thisAnimal = allAnimals.at(i);

    // If this Animal is a parrot
    //   cast to a Parrot*
    //   Do something parroty

  }

}

int main() {
  
  {
    Animal* animal = new Animal();
    animal->printName();
    animal->getAge();
    delete animal;
  }
  cout << "-----" << endl;
  {
    Animal* bird = new Bird();
    bird->printName();
    bird->getAge();
    delete bird;
  }
  cout << "-----" << endl;
  {
    Parrot* parrot = new Parrot();
    parrot->printName();
    parrot->getAge();
    parrot->canTalk();
    delete parrot;
  }



}
