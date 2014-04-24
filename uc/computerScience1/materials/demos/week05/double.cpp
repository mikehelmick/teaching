// week05/double.cpp

#include <fstream>
#include <iostream>

using namespace std;

int main() {

  ifstream in;
  in.open("input.txt");
  ofstream out;
  out.open("output.txt");

  int value;

  in >> value;
  while (value >= 0) {
    int transformed = value * 2;
    out << transformed << endl;
    in >> value; 
  }

  // close both files
  in.close();
  out.close();

  return 0;
}
