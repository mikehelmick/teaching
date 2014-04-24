
#include <Dictionary.h>

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

Dictionary::Dictionary(const string filename) {
  ifstream inFile;
  inFile.open(filename.c_str());

  string line;
  while (!inFile.eof()) {
    getline(inFile, line);
    if (line.size() > 4) {
      words.push_back(line);
    }
  }

  inFile.close();

  // Seed random
  srand(time(NULL));
}

Dictionary::~Dictionary() {
  // nothing to do
}

string Dictionary::getRandomWord() const {
  int wordIdx = rand() % words.size();
  return words[wordIdx];
}

int Dictionary::getWordCount() const {
  return words.size();
}
