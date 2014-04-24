#include <iostream>
#include <iomanip>  // formatting
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
  if (argc != 3) {
    cout << "Please enter an input file name and output file name" << endl;
    return 1;
  }

  ifstream inFile;
  inFile.open(argv[1]);

  int wordCount = 0;

  while (!inFile.eof()) {
    string word;
    inFile >> word;

    if (word != "") {
      cout << word << endl;
      wordCount++;
    }
  }


  inFile.close();

  cout << "I found " << wordCount << " words." << endl;

  return 0;
}
