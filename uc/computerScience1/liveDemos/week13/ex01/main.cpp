#include <cstdlib>
#include <iostream>
using namespace std;

#include <Circle.h>

int main() {
  srand(time(NULL));

  int limit = rand() % 1000 + 50;
  for (int i = 0; i < limit; i++) {
    Circle c(rand() % 50 + 10);
    cout << "Circle area: " << c.getArea() << endl;
  }

  // Invoke the static method to get the # of circles ever created
  cout << "# Circles created: " << Circle::getCirlceCreationCount() << endl;
}
