// Game of life, using a 1D array to simulate 2D array
//
#include <cstdlib>
#include <iostream>
#include <unistd.h>
using namespace std;

const char DEAD = '.';
const char ALIVE = 'O';

const int NUM_NEIGHBORS = 8;
const int R_NEIGHBORS[] = {-1, -1, 0, 1, 1,  1,  0, -1};
const int C_NEIGHBORS[] = { 0,  1, 1, 1, 0, -1, -1, -1};

bool isDead(char* board, int width, int height) {
  for (int r = 0; r < height; r++) {
    for (int c = 0; c < width; c++) {
      if (*(board + r * width + c) == ALIVE) {
        return false;
      }
    }
  }
  return true;
}

void printBoard(char* board, int width, int height) {
  for (int r = 0; r < height; r++) {
    for (int c = 0; c < width; c++) {
      cout << board[r * width + c] << " ";
    }
    cout << endl;
  }
  cout.flush();
}

bool isValidPosition(int r, int c, int width, int height) {
  return r >= 0 && r < height && c >= 0 && c < width;
}

char calculateCell(char* board, int r, int c, int width, int height) {
  int neighborCount = 0;
  for (int i = 0; i < NUM_NEIGHBORS; i++) {
    int nR = r + R_NEIGHBORS[i];
    int nC = c + C_NEIGHBORS[i];
    if (isValidPosition(nR, nC, width, height)) {
      if (*(board + nR * width + nC) == ALIVE) {
        neighborCount++;
      }
    }
  }

  char current = *(board + r * width + c);
  if (current == ALIVE && (neighborCount < 2 || neighborCount > 3)) {
    return DEAD;
  } else if (current == ALIVE && (neighborCount == 2 || neighborCount == 3)) {
    return ALIVE;
  } else if (current == DEAD && neighborCount == 3) {
    return ALIVE;
  }

  return DEAD;
}

char* advance(char* board, int width, int height) {
  char* nextGen = new char[width * height];
  for (int r = 0; r < height; r++) {
    for (int c = 0; c < width; c++) {
      nextGen[r * width + c] = calculateCell(board, r, c, width, height);
    }
  }
  delete[] board;
  return nextGen;
}

int main(int argc, char* argv[]) {
  // Default generations to run is 100, but allow the user
  // to pass in a different value on the command line. Example:
  // ./a.out 50
  int generationsToRun = 100;
  if (argc > 1) {
    generationsToRun = atoi(argv[1]);
  }

  // Initialize the board
  int width = 0;
  int height = 0;
  cin >> width >> height;

  char* board = new char[width * height];
  for (int r = 0; r < height; r++) {
    for (int c = 0; c < width; c++) {
      char status;
      cin >> status;
      *(board + r * width + c) = status;
    }
  }
  cout << "\033[2J\033[1;1H";

  cout << "--- STARTING ---" << endl;
  printBoard(board, width, height);


  for (int generation = 1; generation <= generationsToRun && !isDead(board, width, height); generation++) {
    usleep(90000);
    std::cout << "\033[1;1H";
    cout << "--- GENERATION #" << generation << " ---" << endl;
    board = advance(board, width, height); 
    printBoard(board, width, height);
  }

  //cout << "--- FINAL BOARD ---" << endl;
  //printBoard(board, width, height);
  delete[] board;
}
