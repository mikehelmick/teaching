#ifndef SUDOKU_H
#define SUDOKU_H
/*
 * Sudoku.h
 * Name: FILL ME IN
 *
 * Oct 23 ,2013
 */

#include <string>
#include <vector>
using namespace std;

typedef string board_t;   // Convenience so we don't get confused with what a board is.
                          // Feel free to change!

class Sudoku{
public:
  /* REQUIRED FOR LAB */
  /* Constructor that takes in a string of 81 characters representing a sudoku
   * state containing digits 1-9 or . for a blank square.
   */
  Sudoku(const string& state);
  
  /* REQUIRED FOR LAB */
  /* Returns true if the current board state is valid (doesn't have any 
   * sudoku violations).  The current state before solve() is called is the beginning
   * state, otherwise it's the solved board state.
   */
  bool isValid();
  
  /* REQUIRED FOR LAB */
  /* Returns true if the current board state is complete (all boxes filled in) 
   * and valid.  The current state before solve() is called is the beginning
   * state, otherwise it's the solved board state.
   */
  bool isComplete();
  
  /* REQUIRED FOR LAB */
  /* Prints the current board state in an easy-so understate way. If solve hasn't been 
   * called, returns the starter board, otherwise a solved board. */
  void printCurrentBoard();
  
  /* Returns the starter board, the one given to the constructor above. */
  string getStartBoard();
  
  /* Returns the current board.  If solve hasn't been called, returns the starter
   * board, otherwise a solved board. */
  string getCurrentBoard();
  
  /* The public solve function that solves the board given in the constructor.
   * Non-recursive, so this will probably just call the internal recursive solve. */
  bool solve();




private:
  
  // You may add or remove ANY private functions or variables as you see fit 
  
  Sudoku(); 
  
  bool solve(const board_t& state);  // Internal recursive solve function
                // Here taking in a string, but you may represent your board as anything
                
  /* Given a board state, this returns all possible valid board states with one 'move'.
   * In Sudoku, that is probably all possible ways of filling in the next empty spot.
   */
  vector<board_t> getSuccessors(const board_t& state);
  
  // Private helper functions.  Here as only a suggestion.
  void printCurrentBoard(const board_t& state);
  bool isValid(const board_t& state);
  bool isComplete(const board_t& state);

  // Private variables Here as only a suggestion.
  board_t startstate;
  board_t currentstate;
  
  friend class SudokuTest;    // Lets the test suite inside the class
                              // Therefore a unit test can test private functions.
  
};

#endif