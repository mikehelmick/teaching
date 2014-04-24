#ifndef SUDOKU_TEST_H
#define SUDOKU_TEST_H

#include <Sudoku.h>

#include <iostream>
#include <cxxtest/TestSuite.h>

using namespace std;

class SudokuTest : public CxxTest::TestSuite {
public:
	
  void testallUnique() {
    Sudoku s;
    TS_ASSERT(s.allUnique("bla"));
    TS_ASSERT(s.allUnique("12345"));
    TS_ASSERT(s.allUnique("....."));
    TS_ASSERT(s.allUnique("1234..."));
    TS_ASSERT(! s.allUnique("1231"));
    TS_ASSERT(! s.allUnique("1..231"));
  }
  
  void testisValidCol(){
    Sudoku g;
    string s = ".........456789123789123456234567891567891234891234567345678912678912345912345678";
    TS_ASSERT(g.isValid(s));
    s[0] = '4';
    TS_ASSERT(! g.isValid(s));
  }
  
  void testisValidRow(){
    Sudoku g;
    string s = ".........456789123789123456234567891567891234891234567345678912678912345912345678";
    TS_ASSERT(g.isValid(s));
    s[11] = '4';
    TS_ASSERT(! g.isValid(s));
  }
  
  void testisValidBox(){
    Sudoku g;
    string s = ".................................................................................";
    TS_ASSERT(g.isValid(s));
    s[0] = '1';
    s[10] = '1';
    TS_ASSERT(! g.isValid(s));
  }
  
  void testisComplete(){
    Sudoku g;
    string s = ".................................................................................";
    TS_ASSERT(! g.isComplete(s));
    s = "123456789456789123789123456234567891567891234891234567345678912678912345912345678";
    TS_ASSERT( g.isComplete(s));
  }
  
  void testSuccessors(){
    Sudoku g;
    string s = ".................................................................................";
    vector<board_t> valids = g.getSuccessors(s);
    TS_ASSERT(valids.size() == 9);
    for(unsigned int i = 0; i < valids.size(); i++){
      TS_ASSERT( g.isValid(valids[i]));
    }
    
    s = ".........456789123789123456234567891567891234891234567345678912678912345912345678";
    valids = g.getSuccessors(s);
    TS_ASSERT(valids.size() == 1);
    for(unsigned int i = 0; i < valids.size(); i++){
      TS_ASSERT( g.isValid(valids[i]));
    }
  }
  
  void testSolve(){
    string s = ".........456789123789123456234567891567891234891234567345678912678912345912345678";
    Sudoku g(s);
    TS_ASSERT(g.solve());
    s = g.getCurrentBoard();
    string sol = "123456789456789123789123456234567891567891234891234567345678912678912345912345678";
    TS_ASSERT(s.compare(sol) == 0);
  }
	// This is probably only a third of how many tests you should have!
};
  
#endif