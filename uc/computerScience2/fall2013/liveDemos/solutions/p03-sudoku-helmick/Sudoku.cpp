/*
 * Sudoku.cpp
 *
 *  Created on: Oct 22, 2013
 *      Author: helmicmt
 */
#include <Sudoku.h>

#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
using namespace std;

const int Sudoku::SIZE = 81;

Sudoku::Sudoku(const string& state) {
  // build the inital board
  startstate = new int[SIZE];
  currentstate = new int[SIZE];

  for (int i = 0; i < state.length(); i++) {
    if (state[i] == '.') {
      startstate[i] = 0;
      currentstate[i] = 0;
    } else {
      int val = state[i] - '0';
      startstate[i] = val;
      currentstate[i] = val;
    }
  }
}

Sudoku::~Sudoku() {
  delete startstate;
  delete currentstate;
}

bool Sudoku::isValid() {
  return isValid(startstate);
}

bool Sudoku::isComplete() {
  return isComplete(startstate);
}

string Sudoku::boardToString(const int* state) {
  string s;
  for (int i = 0; i < SIZE; i++) {
    s.push_back(state[i] + '0');
  }
  return s;
}

void Sudoku::printCurrentBoard() {
  for (int i = 0; i < SIZE; i++) {
    if (i > 0 && i % 9 == 0) {
      cout << endl;
    }
    if (currentstate[i] == 0) {
      cout << " .";
    } else {
      cout << setw(2) << currentstate[i];
    }
  }
  cout << endl;
}

string Sudoku::getStartBoard() {
  return boardToString(startstate);
}

string Sudoku::getCurrentBoard() {
  return boardToString(currentstate);
}

void Sudoku::printState() {

}

bool Sudoku::solve() {
  if (isComplete(currentstate)) {
    return true;
  }
  // board isn't solvable (not valid)
  if (!isValid(currentstate)) {
    return false;
  }
  
  // Boostrap, find index of first zero
  int idx = 0;
  while (currentstate[idx] != 0) {
    idx++;
  }
  return solve(currentstate, idx);
}

Sudoku::Sudoku() {
  // nada
}

bool Sudoku::solve(int* current, int idx) {
  if (isComplete(current)) {
    return true;
  }
  //if (!isValid(current)) {
    //cout << " ** no solution " << endl;
  //  return false;
  //}
  if (idx >= SIZE) {
    return false;
  }

  // Find the next index to fill in. If it doesn't exist, this is a terminal condition.
  int nextIdx = idx + 1;
  while (nextIdx < SIZE && current[nextIdx] != 0) {
    nextIdx++;
  }
  
  // try each number at this position
  for (int num = 1; num < 10; num++) {
    current[idx] = num;
    //cout << "trying " << num  << " at " << setw(2) << idx << " :: " << boardToString(current) << endl;
    //printCurrentBoard();
    if (isValid(current) && solve(current, nextIdx)) {
      return true;
    }
  }
  
  // If we get here, there is no solution down this path, revert the item at this idx.
  current[idx] = 0;
  return false;
}

int** Sudoku::getSuccessors(const int* state) {

}

bool Sudoku::isValid(const int* state) {
  bool valid = true;
  // Check rows
  for (int row = 0; valid && row < 9; row++) {
    int offset = row * 9;
    int x[] = {
        state[offset + 0], state[offset + 1], state[offset +  2],
        state[offset + 3], state[offset + 4], state[offset +  5],
        state[offset + 6], state[offset + 7], state[offset +  8]};
    valid = isSectorValid(x);
    //cout << "row " << row << " valid=" << valid << endl;
  }
  // Check columns
  for (int col = 0; valid && col < 9; col++) {
    int x[] = {
        state[col + 0], state[col + 9], state[col + 18],
        state[col + 27], state[col + 36], state[col + 45],
        state[col + 54], state[col + 63], state[col + 72]};
    valid = isSectorValid(x);
    //cout << "col " << col << " valid=" << valid << endl;
  }
  // Check boxes
  for (int row = 0; valid && row < 3; row++) {
    for (int col = 0; valid && col < 3; col++) {
      int offset = row * 27 + col * 3;
      int x[] = {
          state[offset + 0], state[offset + 1], state[offset + 2],
          state[offset + 9], state[offset + 10], state[offset + 11],
          state[offset + 18], state[offset + 19], state[offset + 20]};
      valid = isSectorValid(x);
      //cout << "box " << row << "," << col << " valid=" << valid << endl;
    }
  }
  
  return valid;
}

bool Sudoku::isSectorValid(const int *sector) {
  int x[9];
  for (int i = 0; i < 9; i++) {
    x[i] = 0;
  }
  for (int i = 0; i < 9; i++) {
    // only check things that aren't zero
    if (sector[i] != 0) {
      if (x[sector[i]-1] == 0) {
        x[sector[i]-1] = 1;
      } else {
        return false;
      }
    }
  }
  return true;
}

bool Sudoku::isComplete(const int* state) {
  bool noZeros = true;
  for (int i = 0; noZeros && i < SIZE; i++) {
    noZeros = state[i] != 0;
  }
  return noZeros && isValid(state);
}


