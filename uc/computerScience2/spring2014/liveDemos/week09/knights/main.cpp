/* Knights tour */
#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>

using namespace std;

const int BOARD_SIZE = 8;
const int MOVES = 8;

static unsigned long long calls = 0;

int rOffsets[8] = {-2, -1, 1, 2,  2,  1, -1, -2};
int cOffsets[8] = { 1,  2, 2, 1, -1, -2, -2, -1};

void initBoard(int board[BOARD_SIZE][BOARD_SIZE]) {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      board[i][j] = 0;
    }
  }
}

void printBoard(int board[BOARD_SIZE][BOARD_SIZE]) {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      cout << setw(3) << board[i][j];
    }
    cout << endl;
  }
}

bool isComplete(int board[BOARD_SIZE][BOARD_SIZE]) {
  bool complete = true;
  for (int i = 0; i < BOARD_SIZE && complete; i++) {
    for (int j = 0; j < BOARD_SIZE && complete; j++) {
      if (board[i][j] == false) {
        complete = false;
      }
    }
  }
  return complete;
}

bool isValidSpace(int r, int c) {
  return r >= 0 && r < BOARD_SIZE && c >= 0 && c < BOARD_SIZE;
}


bool solve(int board[BOARD_SIZE][BOARD_SIZE], int r, int c, int depth) {
  //cout << "testing " << r << "," << c << " at depth: " << depth << endl;
  //printBoard(board);
  //calls++;
  //if (calls % 10000 == 0) {
  //  cout << "CALLS: " << calls << endl;
  //}

  if (isComplete(board)) {
    cout << "SOLVED!" << endl;
    printBoard(board);
    return true;
  }

  // get successors
  for (int moveIdx = 0; moveIdx < MOVES; moveIdx++) {
    int nR = r + rOffsets[moveIdx];
    int nC = c + cOffsets[moveIdx];
    if (!isValidSpace(nR, nC)) {
      // Move would take us off the board, skip it
      continue;
    }
    if (board[nR][nC] != 0) {
      // Space is already occupied
      continue;
    }

    // test successors
    board[nR][nC] = depth + 1;

    if (solve(board, nR, nC, depth + 1)) {
      return true;
    }

    // didn't work - undo what we've done here.
    board[nR][nC] = 0;
  }
  //for (int i = 0; i < depth; i++) {
  //  cout << " ";
  //}
  //cout << r << "," << c << " at depth: " << depth << endl;
  return false;
}

int main() {
  int board[BOARD_SIZE][BOARD_SIZE];
  initBoard(board);
  cout << "Starting board" << endl;
  printBoard(board);

  cout << "Enter starting point: ";
  int x, y;
  cin >> x >> y;
  board[x][y] = 1;

  if (!solve(board, x, y, 1)) {
    cout << "Couldn't solve board" << endl;
  }

}
