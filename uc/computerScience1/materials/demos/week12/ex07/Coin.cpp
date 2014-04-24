// ex07/Coin.cpp
#include <iostream>
#include <cstdlib>
using namespace std;

class Coin {
public:

  // "Default" or zero-argument constructor
  Coin() {
    flipCount = 0;
    headsCount = 0;
    tailsCount = 0;
    // Flip the coin to start with.
    flip();
  }

  void flip() {
    heads = rand() % 2 == 1;
    flipCount++;
    if (heads) {
      headsCount++;
    } else {
      tailsCount++;
    }
  } 

  bool isHeads() {
    return heads;
  }

  int getFlipCount() {
    return flipCount;
  }

  int getHeadsCount() {
    return headsCount;
  }

  int getTailsCount() {
    return tailsCount;
  }

private:
  bool heads;
  int flipCount;
  int headsCount;
  int tailsCount;
};

int main() {
  srand(time(NULL));

  Coin c;

  for (int i = 0; i < 1000; i++) {
    c.flip();
    cout << c.getFlipCount() << " : ";
    if (c.isHeads()) {
      cout << "heads" << endl;
    } else {
      cout << "tails" << endl;
    }
  }

  cout << "#heads : " << c.getHeadsCount() << endl;
  cout << "#tails : " << c.getTailsCount() << endl;
}
