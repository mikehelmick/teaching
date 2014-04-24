#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

  ifstream inFile;
  inFile.open("input2.txt");

  int numLines = 0;
  inFile >> numLines;

  for (int i = 0; i < numLines; i++) {
    string word;
    int dup;
    inFile >> word >> dup;

    for (int j = 0; j < dup; j++) {
      cout << word << " ";
    }
    cout << endl;
  }


  inFile.close();
  return 0;
}
