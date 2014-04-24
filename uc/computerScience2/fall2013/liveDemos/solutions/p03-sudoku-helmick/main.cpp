/*
 * main.cpp
 *
 *  Created on: Oct 22, 2013
 *      Author: helmicmt
 */

#include <Sudoku.h>

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {

  // state 2
  //Sudoku s("1.657..9.84..2.1...5.9.4...6.....2.3.82.9.74.4.7.....1...4.2.1...5.8..39.7..598.2");
  
  // state 6
  //Sudoku s("...5..68...8.19.......3..1.3....8..679.165.484..7....5.1..5.......32.5...37......");
  
  // state 7
  Sudoku s(".7.39.........85.9....5.1...2.1..3.44.3...2.56.8..4.9...2.4....7.65.........17.4.");
  
  
  cout << "isValid = " << s.isValid() << " isComplete = " << s.isComplete() << endl;
  s.printCurrentBoard();
  cout << "startig solve" << endl;
  s.solve();
  cout << "solved" << endl;
  s.printCurrentBoard();

}


