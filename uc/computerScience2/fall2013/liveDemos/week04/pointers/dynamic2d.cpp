#include <iostream>

using namespace std;

// Board is a 2D array of size dim
void printBoard(int* board[], int dim) {
  for (int y = 0; y < dim; y++) {
    for (int x = 0; x < dim; x++) {
      cout << board[y][x] << " ";
    }
    cout << endl;
  }
}

void printAddresses(int* board[], int dim) {
  cout << "Address of board: " << &board << endl;
  for (int y = 0; y < dim; y++) {
    cout << "&board[" << y << "]= " << &board[y] << " : ";
    for (int x = 0; x < dim; x++) {
      cout << &board[y][x] << " ";
    }
    cout << endl;
    for (int x = 0; x < dim; x++) {
      cout << *((*(board + y)) + x) << " ";
    }
    
    cout << endl;
  }
}

int main() {
  int dim = 3;
  int** sudoku_board = new int*[dim];
  for (int i = 0; i < dim; i++) {
    sudoku_board[i] = new int[dim];
  }

  printBoard(sudoku_board, dim);
  printAddresses(sudoku_board, dim);

  // Free up memory  
  for (int i = 0; i < dim; i++) {
    delete sudoku_board[i];
  }
  delete sudoku_board;
}














