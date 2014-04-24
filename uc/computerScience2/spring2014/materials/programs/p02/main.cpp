#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

#include <Card.h>
#include <Deck.h>
#include <InBetween.h>

int main(int argc, char* argv[]) {
  if (argc == 1) {
    srand(time(NULL));
  } else {
    srand(atoi(argv[1]));
  }

  cout << "Welcome to \"In Between\"" << endl;

  InBetween* inBetween = new InBetween();
  inBetween->play();

  cout << "Thanks for playing." << endl;
  cout << "You ended with $: " << inBetween->getBalance() << endl;

  delete inBetween;
}
