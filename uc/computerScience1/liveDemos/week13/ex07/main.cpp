#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
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

  // Point* p = new Point(1, 2);
  // delete p;

  vector<Point*> points;
  readPoints(points);

  // print all of the points out
  for (unsigned int i = 0; i < points.size(); i++) {
    cout << points[i]->toString() << " ";
  }  

  // clean up the points
  for (unsigned int i = 0; i < points.size(); i++) {
    delete points[i];
  }
  points.clear();
}
