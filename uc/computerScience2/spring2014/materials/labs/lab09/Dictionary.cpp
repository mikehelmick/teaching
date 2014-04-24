#include <set>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

#include <Dictionary.h>

Dictionary::Dictionary() {
  ifstream inFile;
  inFile.open("wordswithfriends.txt");

  string line;
  while (!inFile.eof()) {
    getline(inFile, line);
    if (line.size() >= 3) {
      words.insert(line);
    }
  }

  inFile.close();
}
  
int Dictionary::getWordCount() const {
  return words.size();
}

bool Dictionary::isWord(string word) const {
  bool found = words.find(word) != words.end();
  return found;
}
