#include <iostream>

using namespace std;

int main() {
  int order = 2;
  int width = order * 4 - 1;
  int height = order * 4;

  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      if (y == 0 || y == height - 1) {
        cout << "+";
      } else if (x == 0 || x == width - 1) {
        cout << "+";
      } else {
        cout << " ";
      }
    }
    cout << endl;
  }
}