/*
 * Sudoku.cpp
 * Name: FILL ME IN
 *
 * Oct 23 ,2013
 */
 
#include <iostream>
#include <string>

#include "Sudoku.h"

using namespace std;

Sudoku::Sudoku(const string& state){
  // FILL ME IN
}

Sudoku::Sudoku(){
  // A default constructor doesn't make any sense in this case, but having this defined
  // here without any code allows a unit test to create a dummy object (with 
  // non-initialized private variables), so that it can test the private functions
  // Takeaway: leave this as is and SudokuTest.h will work as written.
}

void Sudoku::printCurrentBoard(){
  // FILL ME IN
}

string Sudoku::getCurrentBoard(){
  // FILL ME IN
  return "";
}

bool Sudoku::isValid(){
  // FILL ME IN
  return true;
}

bool Sudoku::isComplete(){
  // FILL ME IN
  return true;
}

bool Sudoku::solve(){
  // FILL ME IN
  return true;
}

void Sudoku::printCurrentBoard(const board_t& state){
  // FILL ME IN
}


bool Sudoku::isValid(const board_t& state){
  // OPTIONALLY FILL ME IN
  return true;
}

bool Sudoku::isComplete(const board_t& state){
  // OPTIONALLY FILL ME IN
  return true;
}

 vector<board_t> Sudoku::getSuccessors(const board_t& state){
  // OPTIONALLY FILL ME IN
  vector<board_t> ret;
  return ret;
 }
 
bool Sudoku::solve(const board_t& state){
  // OPTIONALLY FILL ME IN
  return true;
}