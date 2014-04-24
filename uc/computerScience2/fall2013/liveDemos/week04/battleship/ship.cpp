#include <ship.h>


Ship::Ship(int size) : size(size), hits(0) {
}

Ship::Ship() : size(0) {
}

int Ship::getSize() {
  return 0;
}

bool Ship::isSunk() {
  return false;
}

void Ship::hit() {
  
}
