/*
 * Sudolu.cpp
 * Name: Paul Talaga
 *
 * This class solves a sudoku puzzle represented as a string of 81 characters,
 * 1-9, with a '.' as an empty space.
 *
 * The solving technique uses backtracking implemented as a recursive solve function
 * following a basic constraint statisfaction problem (CSP) solution using DFS, as
 * outlined in Russel & Norvig's "Introduction to Artificial Intelligence".
 *
 * The key functions are the getSuccessors, which gets all valid children of a 
 * node (state) with only 1 blank spot filled in.  Thus the recursive solve makes 
 * progess toward a solved game by always calling itself with a more solved
 * board.  If no solution is possible (given a bard), solve returns false.
 *
 * Additional class methods are used to get and print the 'current'/solved
 * board.
 *
 * Oct 15, 2013
 */
#include <iostream>
#include <string>

#include "Sudoku.h"

using namespace std;

/* Only public constructor
 * Takes a board as a string of 81 characters, 1-9, plus '.' for empty.
 */
Sudoku::Sudoku(const string& state){
	// We store the board internally as a string, so no conversion is needed.
	// Verify it is of the correct length.
  if(state.size() != 81){
    cout << "Error in given state\n";
    return;
  }
	// Copy the startstate internally
  startstate = state;
  currentstate = state;
}

/* Default constructor - PRIVATE
 * This constructor allows instantiation of the class without providing an 
 * real board.  Usefull in the unit tests of private methods.
 */
Sudoku::Sudoku(){
	startstate = ".................................................................................";
	currentstate = ".................................................................................";
}

/* printCurrentBoard
 * Prints the current board to the screen.
 */
void Sudoku::printCurrentBoard(){
  printBoard(currentstate);
}

/* getCurrentBoard
 * Returns the current board state as a string.
 */
string Sudoku::getCurrentBoard(){
  return currentstate;
}

/* getStartBoard
 * Returns the starting board state as a string.
 */
string Sudoku::getStartBoard(){
  return startstate;
}

/* isValid
 * Returns if the current board is valid, as in it doesn't violate any rules of sudoku.
 * Does not have to be solved.
 */
bool Sudoku::isValid(){
  return isValid(startstate);
}

/* isComplete
 * Returns if the current board is complete, as in all filled in and still a valid board.
 */
bool Sudoku::isComplete(){
  return isComplete(startstate);
}

/* solve
 * Attempts to solve the starting board.
 * See private version below for details.
 */
bool Sudoku::solve(){
  return solve(startstate);
}

/* printBoard
 * Given a board, prints it to stdout.
 */
void Sudoku::printBoard(const board_t& state){
  cout << "+---+---+---+\n|";
  for(unsigned int i = 0; i < state.size(); i++){
    cout << state[i];
    if(i % 3 == 2){
      cout << "|";
    }
    if(i% 9 == 8 and i%27 != 26){
      cout << endl << "|";
    }
    if(i%27 == 26 && i < 80){
      cout << "\n+---+---+---+\n|";
    }
  }
  cout << "\n+---+---+---+\n\n";
}

/* allUnique
 * Helper function to isValid that given a string, returns if there aren't any repeated
 * numbers.  Ignores '.'
 */
bool Sudoku::allUnique(const string& s){
  // makes sure all the digits are in the string only once.
  for(unsigned int i = 0; i < s.size(); i++){
    if(s[i] >= '1' && s[i] <= '9'){
      string needle = string(&s[i]);
      needle = needle.substr(0,1);
      if( s.find(needle.c_str(),i+1) != string::npos){
        return false;
      }
    }
  }
  return true;
}

/* isValid
 * Given a board, returns if it is a valid sudoku board, as in it doesn't violate the rules
 * of sudoku.  No repeated numbers in each row, column or box.
 */
bool Sudoku::isValid(const board_t& state){
  // Check columns
  string column;
  for(int x = 0; x < 9; x++){
    for(int y = 0; y < 9; y++){
      column.push_back(state[x + 9 * y]);
    }
    if(! allUnique(column)){
      return false;
    }
    column = "";
  }
  // Check rows
  string row;
  for(int y = 0; y < 9; y++){
    for(int x = 0; x < 9; x++){
      row.push_back(state[x + 9 * y]);
    }
    if(! allUnique(row)){
      return false;
    }
    row = "";
  }
  // Check boxes
  string box;
  for(int x = 0; x < 3; x++){
    for(int y = 0; y < 3; y++){
      int l = x * 3 + y * 27;		// The math to move the box around the board
      box.push_back(state[l]);	// based on x and y of a box.
      box.push_back(state[l+1]);
      box.push_back(state[l+2]);
      box.push_back(state[l+9]);
      box.push_back(state[l+9+1]);
      box.push_back(state[l+9+2]);
      box.push_back(state[l+18]);
      box.push_back(state[l+18+1]);
      box.push_back(state[l+18+2]);
      if(! allUnique(box)){
        return false;
      }
      box = "";
    }
  }
  return true;
}

/* isComplete
 * Given a board (as a string) return true if the board is solved (complete)
 */
bool Sudoku::isComplete(const board_t& state){
  return (state.find(".") == string::npos) && isValid(state);
}


/* getSuccessors
 * Given a board state, returns a list of the valid board states reachable by filling in one 
 * more empty spot.
 */
vector<board_t> Sudoku::getSuccessors(const board_t& state){
  // Returns all successors of a board
  vector<board_t> ret;
  int loc = state.find(".");
  if(loc == string::npos){
    cout << "No successors!\n";
    return ret;
  }
  for(int i = 0; i <9; i++){
    board_t n(state);
    n[loc] = i + '1';
    if( isValid(n)){
      ret.push_back(n);
    }
  }
  return ret;
 }
 
 /* solve
  * Given a board state, attempts to solve the board.  Will return a boolean if the board is solvable 
  * or not.  If a solution is found, prints out the solution and saves the solved board to the
  * currentstate class variable for later retrieval.
  */
bool Sudoku::solve(const board_t& state){
  if( isComplete(state)){
    currentstate = state;
    return true;
  }
  vector<board_t> succ = getSuccessors(state);
  for(unsigned int i = 0; i < succ.size(); i++){
    if( solve(succ[i])){
      return true;
    }
  }
  return false;
}