#include <iostream>
#include <vector>
using namespace std;

class Rectangle {
public:
  Rectangle() : length(0), width(0) {
  }

  Rectangle(double length, double width) {
  	this->length = length;
  	this->width = width;
  }

  void setLength(double length) {
  	this->length = length;
  }

  void setWidth(double width) {
  	this->width = width;
  }

  double getLength() {
  	return length;
  }

  double getWidth() {
  	return width;
  }

  double getArea() {
  	return length * width;
  }

private:
  double length;
  double width;
};

int main() {
  double lengths[4] = {1.2, 2.3, 3.4, 4.5};
  double widths[4] = {2.1, 3.2, 4.3, 5.4};

  Rectangle rectangle[4];
  for (int i = 0; i < 4; i++) {
    rectangle[i].setWidth(widths[i]);
    rectangle[i].setLength(lengths[i]);
  }


  for (int i = 0; i < 4; i++) {
    cout << "l: " << rectangle[i].getLength()
        << " w: " << rectangle[i].getWidth()
        << " area: " << rectangle[i].getArea()
        << endl;
  }
}

