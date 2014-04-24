#ifndef SUDOKU_H
#define SUDOKU_H

#include <string>
#include <vector>
using namespace std;

class Sudoku {
public:
  Sudoku(const string& state);
  virtual ~Sudoku();

  bool isValid();
  bool isComplete();
  void printCurrentBoard();

  string getStartBoard();
  string getCurrentBoard();

  void printState();

  bool solve();

private:
  Sudoku();
  // You may add or remove ANY private functions or variables as you see fit 

  string boardToString(const int* state);

  bool solve(int* current, int idx);  // Internal recursive solve function
  // Here taking in a string, but you may represent your board as anything

  int** getSuccessors(const int* state);
  
  bool isValid(const int* state);
  // an array of size 9, cotaining a specific sector of the board
  bool isSectorValid(const int* sector);
  bool isComplete(const int* state);

  int* startstate;
  int* currentstate;

  static const int SIZE;
};

#endif
