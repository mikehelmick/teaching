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

  ofstream outFile;
  outFile.open(argv[2]);

  if (!outFile.is_open()) {
    cout << "ERROR - couldn't open output file for writing." << endl;
    return 1;
  }

  int wordCount = 0;

  const char vowels[] = {'a','e','i','o','u'};

  while (!inFile.eof()) {
    string word;
    getline(inFile, word);

    if (word != "") {
      int vowel = 0;
      int notVowel = 0;
      for (int i = 0; i < word.length(); i++) {
        bool foundVowel = false;
        for (int c = 0; c < 5; c++) {
          if (word[i] == vowels[c]) {
            vowel++;
            foundVowel = true;
            break;
          }
        }
        if (!foundVowel) {
          notVowel++;
        }
      }

      wordCount++;

      outFile << word << " " << word.length() << " " << vowel << " " << notVowel << endl;
    }
  }


  inFile.close();
  outFile.close();
  cout << "I found " << wordCount << " words." << endl;

  return 0;
}
