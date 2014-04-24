#include <iostream>

using namespace std;

struct color {
  int r;
  int g;
  int b;
  float alpha;
};

void printValue(int x) {
  cout << "x is " << x << endl;
}

void printValues(color &col) {
  printValue(col.r);
}

int main() {
 
  color my_color;
  my_color.r = 1;
  my_color.g = 22;
  my_color.b = 127;
  my_color.alpha = 0.5; 

  printValue(my_color.r);
  printValues(my_color);
}
