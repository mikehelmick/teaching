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

  Point* p1 = new Point(1, 2);
  Point* p2 = new Point(*p1);
 
  cout << "p1: " << p1->toString() << endl;
  cout << "p2: " << p2->toString() << endl;

  delete p1;
  delete p2;
}
