#ifndef SHIP_H
#define SHIP_H

#include <string>

using namespace std;

class Ship {
public:
  Ship(int size);

  int getSize();

  bool isSunk();
  
  void hit();

private:
  const int size;
  int hits;

  // Don't use!
  Ship();

  friend class ShipTest;
};

#endif /* SHIP_H */