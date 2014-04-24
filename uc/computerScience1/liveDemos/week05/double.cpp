#include <fstream>
#include <iostream>

using namespace std;

int main() {

  ifstream inFile;
  inFile.open("input.txt");
  ofstream outFile;
  outFile.open("output.txt");

  long value;
  inFile >> value;
  while (value != -1) {
    outFile << (value * 2) << endl;
    inFile >> value;
  }

  inFile.close();
  outFile.close();

}
