// KNights tour #2

#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <vector>
#include <unordered_set>

using namespace std;

const int BOARD_SIZE = 8;

const int moves[8] = {
   -BOARD_SIZE - BOARD_SIZE - 1, -BOARD_SIZE - BOARD_SIZE + 1,
   -BOARD_SIZE - 2, -BOARD_SIZE + 2,
   BOARD_SIZE - 2, BOARD_SIZE + 2,
   BOARD_SIZE + BOARD_SIZE - 1, BOARD_SIZE + BOARD_SIZE + 1};

typedef vector<int> board_t;

unordered_set<unsigned long long> seen;

bool isComplete(board_t &board) {
  for (unsigned int i = 0; i < board.size(); i++) {
    if (board[i] == 0) {
      return false;
    }
  }
  return true;
}

void printBoard(board_t &board) {
  for (int i = 0; i < board.size(); i++) {
    if (i % BOARD_SIZE == 0) {
      cout << endl;
    }
    cout << setw(3) << board[i];
  }
  cout << endl;
}

int getMaxIndex(board_t &board) {
  int highestIdx = 0;
  for (unsigned int i = 1; i < board.size(); i++) {
    if (board[i] > board[highestIdx]) {
      highestIdx = i;
    }
  }
  return highestIdx;
}

bool isValidMove(int from, int to) {
  if (to < 0 || to >= BOARD_SIZE * BOARD_SIZE) {
    return false;
  }
  int fx = from % BOARD_SIZE;
  int fy = from / BOARD_SIZE;
  int tx = to % BOARD_SIZE;
  int ty = to / BOARD_SIZE;
  return abs(fx - tx) + abs(fy - ty) == 3;
}

unsigned long long getHash(board_t &board) {
  int loc = getMaxIndex(board);
  unsigned long long ret = loc;
  for (int i = 0; i < board.size(); i++) {
    if (board[i] != 0) {
      ret = ret + 1;
    }
    ret = ret << 1;
  }
  return ret;
}

void logVisited(board_t &board) {
  unsigned long long hash = getHash(board);
  seen.insert(hash);
}

bool seenBefore(board_t &board) {
  unsigned long long hash = getHash(board);
  unordered_set<unsigned long long>::const_iterator got =
      seen.find(hash);
  return got != seen.end();
}

vector<board_t> getSuccessors(board_t board) {
  vector<board_t> ret;

  int loc = getMaxIndex(board);

  for (int i = 0; i < 8; i++) {
    int dest = loc + moves[i];
    if (board[dest] == 0 && isValidMove(loc, dest)) {
      board_t newboard(board);
      newboard[dest] = newboard[loc] + 1;
      if (!seenBefore(newboard)) {
        ret.push_back(newboard);
      }
    }
  }

  return ret;
}

bool solve(board_t board, int depth) {
  if (isComplete(board)) {
    printBoard(board);
    return true;
  }

  logVisited(board);
  vector<board_t> children = getSuccessors(board);
  for (unsigned int i = 0; i < children.size(); i++) {
    if (solve(children[i], depth + 1)) {
      return true;
    }
  }
  return false;
}

int main() {
  board_t startingBoard;
  for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; i++) {
    startingBoard.push_back(0);
  }

  startingBoard[6] = 1;
  printBoard(startingBoard);

  if (!solve(startingBoard, 1)) {
    cout << "Couldn't solve board." << endl;
  }
}
