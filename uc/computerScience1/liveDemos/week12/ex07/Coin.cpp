#include <iostream>
#include <cstdlib>
using namespace std;

class Coin {
public:
  // Constructor for the Coin class
  Coin() {
    commonInit();
    flip();
  }

  Coin(bool initialState) {
    commonInit();
    heads = initialState;
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

  int getHeadsCount() const {
    return headsCount;
  }

  int getTailsCount() const {
    return tailsCount;
  }

  bool isHeads() const {
    return heads;
  }

  int getFlipCount() const {
    return flipCount;
  }

private:
  bool heads;
  int flipCount;
  int headsCount;
  int tailsCount;

  void commonInit() {
    flipCount = 0;
    headsCount = 0;
    tailsCount = 0;  
  }
};

int main() {
  srand(time(NULL));
  Coin c(true);

  for (int i = 0; i < 1000; i++) {
    c.flip();
    cout << c.getFlipCount() << " : ";
    if (c.isHeads()) {
      cout << "heads" << endl;
    } else {
      cout << "tails" << endl;
    }
  }
  cout << "#heads: " << c.getHeadsCount() << endl;
  cout << "#tails: " << c.getTailsCount() << endl;
}




