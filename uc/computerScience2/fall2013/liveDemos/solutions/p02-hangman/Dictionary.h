/**
 * @author Mike Helmick - mike.helmick@uc.edu
 *
 * Interface for a simple dictionary that can return random workds from
 * the file passed in on the constructor.
 */
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
  Dictionary();
  vector<string> words;
};

#endif