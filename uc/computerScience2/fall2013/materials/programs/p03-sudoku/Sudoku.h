#ifndef SUDOKU_H
#define SUDOKU_H
/*
 * Sudoku.h
 * Name: Paul Talaga
 *
 * Class to solve a sudoku game.
 *
 * Oct 21, 2013
 */

#include <string>
#include <vector>
using namespace std;

typedef string board_t;  // How we represent a board

class Sudoku{
public:
  Sudoku(const string& state);
  
  bool isValid();
  bool isComplete();
  void printCurrentBoard();
  
  string getStartBoard();
  string getCurrentBoard();
  
  void printState();
  
  bool solve();


private:
  Sudoku();
  
  bool solve(const board_t& state);  
                
  vector<board_t> getSuccessors(const board_t& state);
  
  void printBoard(const board_t& state);
  bool isValid(const board_t& state);
  bool isComplete(const board_t& state);
  
  bool allUnique(const string& s);

  board_t startstate;
  board_t currentstate;
  
  friend class SudokuTest;    // Lets the test suite inside the class
  
};

#endif