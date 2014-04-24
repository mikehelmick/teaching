/**
 * @author Paul Talaga paul.talaga@uc.edu
 * @date 9/20/2013
 *
 * Prints a spiral on the screen.
 */

#include <iostream>

using namespace std;

char getMark(int x, int y, int order, int width, int height){
  char mark = '+';
  // Break the spiral into 4 quadrants
  if( y <= x + 1 && y < width - x && y%2 == 0){  // Top
    // note the x + 1, this causes the bridge
    return mark;
  }
  if(y > x && y > width - x && y%2 ==  1){  // Bottom
    return mark;
  }
  if(y-1 > x && y <= width -x && x%2 == 0){  // Left
    // note the y-1, this cuts off the top of the left line early
    return mark;
  }
  if(y <=x && y >= width -x && x%2 == 0){  // Right
    return mark;
  }
  return ' ';
}

int main() {
  while (true) {
    int order;
    cout << "Enter the order of the sprial (0 to quit): " << endl;
    cin >> order;
    if (order == 0) {
      break;
    }

    int width = 4 * order -1;
    int height = 4 * order;

    // Line and space per side, shared middle
    char outChar = '+';

    for (int y = 0; y < height; y++) {
      for (int x = 0; x < width; x++) {
        cout << getMark(x, y, order, width, height);
      }
      cout << endl;
    }
  }
}
