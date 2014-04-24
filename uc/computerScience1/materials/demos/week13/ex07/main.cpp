// ex08/main.cpp
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>yes
using namespace std;

#include <Point.h>

void readPoints(vector<Point*> &points) {
  ifstream f;
  f.open("points.txt");

  string line;
  while (!f.eof()) {
  	getline(f, line);
  	if (line != "") {
  	  stringstream ss(line);
  	  double x, y;
  	  ss >> x >> y;
  	  points.push_back(new Point(x, y));
  	}
  }

  f.close();
}

int main() {

  Point* p = new Point(1, 2);
  delete p;

  /*
  vector<Point*> points;
  readPoints(points);

  // print the points
  for (unsigned int i = 0; i < points.size(); i++) {
  	// Need to use arrow operator - we have a pointer to an object
  	// so we both want to dereference it AND access a field
  	cout << points[i]->toString() << " ";
  }

  // now we have a memory leak!
  // it turns out the destructor for vector doesn't clean up pointers
  // (which make senese, the vector doesn't know if you are actually done)
  for (unsigned int i = 0; i < points.size(); i++) {
  	delete points[i];
  }
  points.clear();
  */
}
