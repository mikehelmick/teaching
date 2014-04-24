#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <set>
#include <string>
using namespace std;

class Dictionary {
public:
  Dictionary();
  
  int getWordCount() const;
  bool isWord(string word) const;
  
private:
  set<string> words;
};

#endif
