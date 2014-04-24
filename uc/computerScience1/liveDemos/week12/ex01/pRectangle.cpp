// ex01/pRectangle.cpp
#include <iostream>
using namespace std;

double getArea(double length, double width) {
  return length * width;
}

int main() {
  double lengths[4] = {1.2, 2.3, 3.4, 4.5};
  double widths[4] = {2.1, 3.2, 4.3, 5.4};

  for (int i = 0; i < 4; i++) {
    cout << "l: " << lengths[i]
        << " w: " << widths[i]
        << " area: " << getArea(lengths[i], widths[i])
        << endl;
  }
}