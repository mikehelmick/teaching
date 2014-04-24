#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

const int SIZE = 8;

const char EMPTY = '_';
const char QUEEN = 'Q';

void initBoard(char* board) {
  for (int r = 0; r < SIZE; r++) {
    for (int c = 0; c < SIZE; c++) {
      *(board + r * SIZE + c) = EMPTY;
    }
  }  
}

void printBoard(char* board) {
  for (int r = 0; r < SIZE; r++) {
    if (r == 0) {
      cout << "   ";
      for (int c = 0; c < SIZE; c++) {
        cout << setw(2) << c;
      }
      cout << endl;
    }
    cout << setw(2) << r << " ";
    for (int c = 0; c < SIZE; c++) {
      cout << setw(2) << *(board + r * SIZE + c);
    }
    cout << endl;
  }
}

bool isValid(char* board) {
  int found = 0;
  int rLocs[SIZE];
  int cLocs[SIZE];
  // Check the rows
  for (int r = 0; r < SIZE; r++) {
    int count = 0;
    for (int c = 0; c < SIZE; c++) {
      if (*(board + r * SIZE + c) == QUEEN) {
        count++;
        
        rLocs[found] = r;
        cLocs[found] = c;
        found++;        
      }
    }
    if (count > 1) {
      return false;
    }
  }
  // Check the columns
  for (int c = 0; c < SIZE; c++) {
    int count = 0;
    for (int r = 0; r < SIZE; r++) {
      if (*(board + r * SIZE + c) == QUEEN) {
        count++;
      }
    }
    if (count > 1) {
      return false;
    }
  }
  // Check the diagionals
  for (int i = 0; i < found - 1; i++) {
    for (int j = i + 1; j < found; j++) {
      long dR = labs(rLocs[j] - rLocs[i]);
      long dC = labs(cLocs[j] - cLocs[i]);
      if (dR == dC) {
        // This is the equivalent of a slope 1 line (or -1 w/ abs value)
        return false;
      }
    }
  }
  // we haven't found anything that makes the board invalid, so it must be valid
  return true;
}

void solveBoard(char* board, int start, int dim, int placed, int &solveNum) {  
  // Successors
  for (int i = start; i < dim * dim; i++) {
    if (board[i] == EMPTY) {
      // Check succession from this spot
      board[i] = QUEEN;
      if (isValid(board)) {
        if (placed + 1 == dim) {
          // this is a complete board
          solveNum++;
          cout << "Solution #" << solveNum << endl;        
          printBoard(board);
        } else {
          solveBoard(board, i + 1, dim, placed + 1, solveNum);
        }
      }
      // Unset before repeating
      board[i] = EMPTY;
    }
  }
}


int main() {  
  char* board = new char[SIZE * SIZE];
  initBoard(board);

  int solutions = 0;
  solveBoard(board, 0, SIZE, 0, solutions);
  cout << "Total solutions: " << solutions << endl;
  
  return 0;
}