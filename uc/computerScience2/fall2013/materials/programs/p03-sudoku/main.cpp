/*
 * main.cpp
 * Name: Paul Talaga
 *
 * This program solves a sudoku puzzle by loading the unsolved puzzle from 
 * a file, provided as a command-line argument.  The file should contain 81
 * numbers (may have new-line characters for readability) representing the
 * sudoku board, with '.' characters for blanks.
 * 
 * The program will print a solution, if one is possible, or display that
 * one is not possible.
 *
 * Oct 15, 2013
 */

#include <iostream>
#include <string>
#include <fstream>

#include "Sudoku.h"

using namespace std;

int main(int argc, char* argv[]) {
	// Make sure they entered a file on the command-line.
  if(argc != 2){
    cout << "Enter sudoku board file to solve\n";
    return 0;
  }
	// Open file, read in the strings, one per line, appended together.
  ifstream file;
  file.open(argv[1]);
  if(file.fail()){
  	cout << "Can not open " << argv[1] << ".\n";
		return 0;
  }
  string game = "";
  string line;
  while(file >> line){
    game = game + line;
  }
  file.close();
  
	// Initialize a game witht the provided board state
  Sudoku s(game);		// A Game is just a string of 81 characters
  s.printCurrentBoard();
  
  if(s.solve()){			// This does all the solving, returning false
    cout << "Solution Found!\n";	// if a solution can't be found.
    s.printCurrentBoard();
  }else{
    cout << "Solution not found\n";
  } 
  
  return 0;  
}
