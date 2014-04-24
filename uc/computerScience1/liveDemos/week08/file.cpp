#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

int main() {
  ifstream inFile;
  inFile.open("test.txt");

  string line;
  getline(inFile, line);
  int numRecords = atoi(line.c_str());

  for (int i = 0; i < numRecords; i++) {
    getline(inFile, line);
    cout << " Text: " << line << endl;
    getline(inFile, line);
    cout << "  Int: " << atoi(line.c_str()) << endl;
    getline(inFile, line);
    cout << "Float: " << atof(line.c_str()) << endl;
  }

}
