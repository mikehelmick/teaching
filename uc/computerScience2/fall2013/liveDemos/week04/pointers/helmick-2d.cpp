#include <iostream>

using namespace std;

void fillBoard(int* board[], int dim) {
  for (int y = 0; y < dim; y++) {
    for (int x = 0; x < dim; x++) {
      board[y][x] = y * x;
    }
  }
}

void printBoard(int* board[], int dim) {
  for (int y = 0; y < dim; y++) {
    for (int x = 0; x < dim; x++) {
      cout.width(2);
      cout << board[y][x] << " ";
    }
    cout << endl;
  }
}

void printAddresses(int* board[], int dim) {
  cout << "Address of board: " << board << endl;
  for (int y = 0; y < dim; y++) {
    cout << endl << "ROW " << y << endl;
    cout << board[y] << " :: ";
    for (int x = 0; x < dim; x++) {
      cout << &(board[y][x]) << " ";
    }
    cout << endl; 
    
    cout << board[y] << " :: ";
    for (int x = 0; x < dim; x++) {
      cout << (*(board + y) + x) << " ";
    }
    
    cout << endl;
  }
}


int main() {
  int dim = 9;
  int** sudoku_board = new int*[dim];
  int** board2 = new int*[dim];
  for (int i = 0; i < dim; i++) {
    sudoku_board[i] = new int[dim];
    board2[i] = new int[dim];
  }
  
  fillBoard(sudoku_board, dim);
  fillBoard(board2, dim);

  printBoard(sudoku_board, dim);
  printBoard(board2, dim);
  printAddresses(sudoku_board, dim);
  printAddresses(board2, dim);

  cout << "sizeof(sudoku_board) = " << sizeof(sudoku_board) << endl;

  // Cleanup array
  for (int i = 0; i < dim; i++) {
    delete sudoku_board[i];
  }
  delete sudoku_board;
}