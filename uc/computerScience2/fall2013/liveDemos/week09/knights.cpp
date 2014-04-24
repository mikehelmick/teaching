/*
 * knights.cpp
 * Paul Talaga
 * 
 * Solves a knights-tour problem.
 *
 * Your program should have better function descriptions, outlining input and output
 * types and meanings.  I ignore them here for readability on the projected screen.
 *
 * Oct 24, 2013
 */

#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

const int BOARD_SIZE = 6;   // Make the board size a constant, so we can easily change

typedef vector<int> board_t;  // For simplicity, we define a new type for a board
                              // as simply a vector of ints, which we interpret as a 
                              // 2D board

bool isComplete(board_t board){       // Return true if the board is done!
  for(int i = 0; i < board.size(); i++){
    if(board[i] == 0){                // If any '0's exist, there are empty spots
      return false;										// and we're not done.
    } 
  } 
  return true;
}

void printBoard(board_t board){   // Prints the given board to the screen
  for(int i = 0; i < board.size(); i++){
    if(i % BOARD_SIZE == 0){
      cout << endl;
    }
    cout.width(3);
    cout << board[i] ;
  }
  cout << endl << endl;
}

int getMaxIndex(board_t board){   // Returns the index of the maximum value
	if(board.size() == 0){					// This corresponds to the current location of the knight.
		return -1;										// board[0] will segfault if the board doesn't
	}																// contain any values.  We check to make sure.
  int max = board[0];             
  int imax = 0;                   
  for(int i = 0; i < board.size(); i++){
    if(board[i] > max){
      max = board[i];
      imax = i;
    }
  }
  return imax;
}
bool isValidMove(int from, int to){ // Returns true if the knight can move from -> to
  if(to < 0 || to >= BOARD_SIZE * BOARD_SIZE){  // Outside our board?
    return false;
  }
  int fx = from % BOARD_SIZE; // Calculate the x,y positions
  int fy = from / BOARD_SIZE;
  int dx = to % BOARD_SIZE;
  int dy = to / BOARD_SIZE;
  return abs(fx-dx) + abs(fy-dy) == 3;  // Make sure the manhattan distance is 3
}

vector<board_t> getSuccessors(board_t board){ // Returns a vector of boards reachable with
  vector<board_t> ret;                        // one move of the knight, based on the
  int loc = getMaxIndex(board);               // passed board.
  int moves[] = {-BOARD_SIZE-BOARD_SIZE-1, -BOARD_SIZE-BOARD_SIZE+1, -BOARD_SIZE+2, BOARD_SIZE+2, BOARD_SIZE+BOARD_SIZE+1, BOARD_SIZE+BOARD_SIZE-1, BOARD_SIZE-2, -BOARD_SIZE-2};   // Hardcode the relative locations of where the knight
  for(int i = 0; i < 8; i++){   // can move, but taking into account a dynamic board size.
    int dest = moves[i] + loc; 
    if( board[dest] == 0 && isValidMove(loc, dest)){  // Is the spot free and a valid location?
      board_t newboard(board);
			newboard[dest] = newboard[loc] + 1;			// Signify where the knight is by 1+ where he was.
			ret.push_back(newboard);
    }
  }
  return ret;
}

bool solve(board_t board){    // Recursive fn to solve a board, takes in a board
  if( isComplete(board) ){    // Base case, is the board solved?
    printBoard(board);				// If so, print it!
    return true;
  }
  vector<board_t> children = getSuccessors(board);  // Get all boards I can get to from here
  for(int i = 0; i < children.size(); i++){
    if( solve(children[i]) ){         // If this partial board was solvable return true
      return true;
    }
  }
  return false;               // No board was solvable so this board not solvable.
}



int main(){
  board_t test;
	// Initialize board full of 0's, meaning the knight hasn't been there yet.
  for(int i = 0; i < BOARD_SIZE * BOARD_SIZE; i++){
    test.push_back(0);
  } 
  test[0] = 1; 		// Place the knight on the board.
	
	printBoard(test);
  
  if(! solve(test)){		// This will print the solution if one exists, or print an error message.
  	cout << "Couldn't solve board. :-(\n\n";
  }
}