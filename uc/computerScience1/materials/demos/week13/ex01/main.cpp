#include <cstdlib>
#include <iostream>
using namespace std;

#include <Circle.h>

int main() {
  srand(time(NULL));

  for (int i = 0; i < 10; i++) {
    Circle c(rand() % 50 + 10);
    cout << "area: " << c.getArea() << endl;
  }

  cout << "Circles created: " << Circle::getCircleCreationCount() << endl;
}