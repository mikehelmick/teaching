#include <iostream>
#include <cstdlib>
using namespace std;

const int BOARD_SIZE = 3;
const char EMPTY = ' ';
const char P1 = 'X';
const char P2 = 'O';

void initBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
  for (int r = 0; r < BOARD_SIZE; r++) {
    for (int c = 0; c < BOARD_SIZE; c++) {
      board[r][c] = EMPTY;
    }
  }
}

void displayBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
  for (int r = 0; r < BOARD_SIZE; r++) {
    if (r == 0) {
       cout << "   ";
       for (int c = 0; c < BOARD_SIZE; c++) {
          cout << c << "   ";
       }
       cout << endl;
    }

    cout << r << ": ";

    for (int c = 0; c < BOARD_SIZE; c++) {
      cout << board[r][c];
      if (c < BOARD_SIZE - 1) {
        cout << " | ";
      }
    }
    cout << endl;
    if (r < BOARD_SIZE - 1) {
      cout << "   ---------";
    }
    cout << endl;
  }
}

bool moveIsValid(char board[BOARD_SIZE][BOARD_SIZE], int row, int col) {
  if ((row < 0 || row >= BOARD_SIZE)
     || (col < 0 || col >= BOARD_SIZE) 
     || (board[row][col] != EMPTY)) {
    return false;
  }

  return true;
}

void doUserMove(char board[BOARD_SIZE][BOARD_SIZE], char player) {

  int row = -1;
  int col = -1;

  cout << "Enter your move, row first, then column: ";
  cin >> row >> col;
  while (!moveIsValid(board, row, col)) {
     cout << "Invalid move. Enter your move, row first, then column: ";
     cin >> row >> col;
  }
  // YAY! I know the move is valid!
  board[row][col] = player;
}

bool boardIsFull(char board[BOARD_SIZE][BOARD_SIZE]) {
  bool emptySpaces = false; 
  for (int r = 0; r < BOARD_SIZE && !emptySpaces; r++) {
    for (int c = 0; c < BOARD_SIZE && !emptySpaces; c++) {
      emptySpaces = board[r][c] == EMPTY;
    }   
  }
  return !emptySpaces;
}

bool gameOver(char board[BOARD_SIZE][BOARD_SIZE]) {
  // Check rows 
  for (int r = 0; r < BOARD_SIZE; r++) {
    if (board[r][0] == board[r][1] && board[r][1] == board[r][2]
        && board[r][0] != EMPTY) {
      cout << "The " << board[r][0] << "'s win!" << endl;
      return true;
    }
  }
  // Check cols
  for (int c = 0; c < BOARD_SIZE; c++) {
    if (board[0][c] == board[1][c] && board[1][c] == board[2][c]
        && board[0][c] != EMPTY) {
      cout << "The " << board[0][c] << "'s win!" << endl;
      return true;
    }
  }
  // Diags 
  if (((board[0][0] == board[1][1] && board[1][1] == board[2][2])
      || (board[2][0] == board[1][1] && board[1][1] == board[0][2]))
      && board[1][1] != EMPTY) {
    cout << "The " << board[1][1] << "'s win!" << endl;
    return true;
  }

  if (boardIsFull(board)) {
    cout << "DRAW!" << endl;
    return true;
  }

  return false;
}

int main() {
  char board[BOARD_SIZE][BOARD_SIZE]; 
  initBoard(board);
  displayBoard(board);

  while (!gameOver(board)) {
    cout << "Player " << P1 << "'s turn" << endl;
    doUserMove(board, P1);
    displayBoard(board);
    if (!gameOver(board)) {
      cout << "Player " << P2 << "'s turn" << endl;
      doUserMove(board, P2);
      displayBoard(board);
    } else {
      break;
    }
  }
}
