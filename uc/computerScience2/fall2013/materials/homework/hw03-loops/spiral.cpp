/**
 * @author Mike Helmick, mike.helmick@uc.edu
 * @date 9/15/2013
 *
 * Prints a spiral on the screen.
 */

#include <iostream>

using namespace std;

bool printTick(int x, int y, int order, int xdim, int ydim) {
  for (int i = 0; i < order; i++) {
    int yMin = i * 2;
    int xMin = i * 2;
    int yMax = ydim - i * 2;
    int xMax = xdim - i * 2;
    if ((x == xMin || x == xMax) && y >= yMin && y <= yMax) {
      // "punch out the spot on the left bar, below the top bounding bar"
      if (!(x == xMin && y == yMin + 1)) {
        return true;
      }
    }
    if ((y == yMin || y == yMax) && x >= xMin && x <= xMax) {
      return true;
    }
    // Add on "bridge coordinates"
    if (x == xMin - 1 && y == yMin) {
      return true;
    }
  }
  return false;
}

int main() {
  while (true) {
    int order;
    cout << "Enter the order of the sprial (0 to quit): " << endl;
    cin >> order;
    if (order == 0) {
      break;
    }

    //printTick(0, 0, 5, 5*4-2, 5*4-1);
    //return 0;

    // Line and space per side, shared middle
    int xdim = order * 4 - 2;
    int ydim = order * 4 - 1; 
    char outChar = '+';

    for (int y = 0; y <= ydim; y++) {
      for (int x = 0; x <= xdim; x++) {
        if (printTick(x, y, order, xdim, ydim)) {
          cout << outChar;
        } else {
          cout << " ";
        }
      }
      cout << endl;
    }
  }
}
