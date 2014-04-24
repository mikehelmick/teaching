#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

#include <Shape.h>
#include <ShapeFactory.h>
#include <cstdlib>

using namespace std;

int main() {

  ifstream inFile;
  inFile.open("shapes.txt");

  int shapeCount;
  inFile >> shapeCount;

  vector<Shape*> shapes;
  for (int i = 0; i < shapeCount; i++) {
    Shape* newShape = ShapeFactory::getShape(inFile);
    if (newShape != NULL) {
      shapes.push_back(newShape);
    }
  }

  double area = 0;
  double volume = 0;
  for (unsigned int i = 0; i < shapes.size(); i++) {
    Shape* shape = shapes[i];
    cout << shape->getName() 
        << ": area: " << setprecision(2) << fixed << shape->getSurfaceArea()
        << " volume: " << setprecision(2) << fixed << shape->getVolume() << endl;
    area += shape->getSurfaceArea();
    volume += shape->getVolume();
  }
  cout << "Total area: " << setprecision(2) << area << endl;
  cout << "Total volume: " << setprecision(2) << volume << endl;

  for (unsigned int i = 0; i < shapes.size(); i++) {
    delete shapes[i];
  }
}
