#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <string>
#include <vector>
using namespace std;

class Dictionary {
public:
  Dictionary(const string filename);
  virtual ~Dictionary();

  string getRandomWord() const;
  int getWordCount() const;

private:
  vector<string> words;
};

#endif