#ifndef SUDOKU_TEST_H
#define SUDOKU_TEST_H

#include <Sudoku.h>

#include <iostream>
#include <cxxtest/TestSuite.h>

using namespace std;

class SudokuTest : public CxxTest::TestSuite {
public:

  // FILL IN MORE HERE
  
  void testisComplete(){
    Sudoku g; // This relies on a default constructor being implemented (empty is OK).
              // Currently it is in private, but since we've made SudokuTest a friend of
              // the Sudoku class (see line 85 in Sudoku.h), it can reach in and use
              // the private functions.  Useful for testing individual functions.
              // This completely relies on the fact that we know how Sudoku works inside
              // the class.  This is WHITE-BOX-TESTING because we look in the box/object.
    board_t s = ".................................................................................";
    TS_ASSERT(! g.isComplete(s));
    s = "123456789456789123789123456234567891567891234891234567345678912678912345912345678";
    TS_ASSERT( g.isComplete(s));
  }
  
  // FILL IN MORE HERE
  
  void testSolve(){
            // This is BLACK-BOX-TESTING since we only use public methods.
    board_t s = ".........456789123789123456234567891567891234891234567345678912678912345912345678";
    Sudoku g(s);
    TS_ASSERT(g.solve());
    s = g.getCurrentBoard();
    board_t sol = "123456789456789123789123456234567891567891234891234567345678912678912345912345678";
    TS_ASSERT(s.compare(sol) == 0);
  }
  
  // FILL IN MORE HERE
  
};
  
#endif