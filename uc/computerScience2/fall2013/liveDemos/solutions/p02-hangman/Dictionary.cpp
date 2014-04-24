/**
 * @author Mike Helmick - mike.helmick@uc.edu
 *
 * Interface for a simple dictionary that can return random workds from
 * the file passed in on the constructor.
 */
#include <Dictionary.h>

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

Dictionary::Dictionary() {
  // private - nothing to do.
}

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
