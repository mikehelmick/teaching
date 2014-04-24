// ex06/Coin.cpp
#include <iostream>
#include <cstdlib>
using namespace std;

class Coin {
public:
  void flip() {
    heads = rand() % 2 == 1;
    flipCount++;
  } 

  bool isHeads() {
    return heads;
  }

  int getFlipCount() {
    return flipCount;
  }

private:
  bool heads;
  int flipCount;
};

int main() {

  Coin c;

  for (int i = 0; i < 100; i++) {
    c.flip();
    cout << c.getFlipCount() << " : ";
    if (c.isHeads()) {
      cout << "heads" << endl;
    } else {
      cout << "tails" << endl;
    }
  }

}
