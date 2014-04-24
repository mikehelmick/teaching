// week05/eof.cpp

#include <fstream>
#include <iostream>

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

