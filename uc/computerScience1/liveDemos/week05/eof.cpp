#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main() {

  ifstream inFile;
  inFile.open("input.txt");

  string line;
  while (!inFile.eof()) {
    getline(inFile, line);
    cout << line << endl;
  }

  inFile.close();

}
