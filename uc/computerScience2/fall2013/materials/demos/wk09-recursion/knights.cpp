#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

typedef vector<int> board_t;
const int BSIZE = 8;

int findMax(board_t board){
  int max = board[0];
  int maxi = 0;
  for(int i = 0; i < board.size(); i++){
    if( board[i] > max){
      max = board[i];
      maxi = i;
    }
  }
  return maxi;
}


bool validMove(int from, int to){
  // make sure the manhattan distance from 'from' to 'to' is 3
  // but not on the same line or column
  int fx = from % BSIZE;
  int fy = from / BSIZE;
  int tx = to % BSIZE;
  int ty = to / BSIZE;
  
  if(fx == tx || fy == ty){
    return false;
  }
  if(abs(fx-tx) + abs(fy-ty) != 3){
    return false;
  }
  if(fx < 0 || fy < 0 || tx < 0 || ty < 0){
    return false;
  }
  if( ty >= BSIZE){
    return false;
  }
  //cout << fx << "," <<  fy << "    " << tx << "," << ty << endl;
  return true;
}

bool isDone(board_t board){
  for(int i = 0; i < board.size();i++){
    if( board[i] == -1){
      return false;
    }
  }
  return true;
}



vector<board_t> successors(board_t board){
  vector<board_t> ret;
  int loc = findMax(board);
  int moves[] = {0-BSIZE-BSIZE-1, 0-BSIZE-BSIZE+1, BSIZE+BSIZE-1, BSIZE+BSIZE+1,-2-BSIZE, -2+BSIZE,2-BSIZE,2+BSIZE};
  for(int i = 0; i < 8; i++){
    int newloc = loc + moves[i];
    if(board[newloc] == -1 &&  validMove(loc, newloc)){
      board_t nb(board);
      nb[newloc] = board[loc] + 1;
      ret.push_back(nb);
    }
  }
  return ret;
}

void printBoard(board_t board){
  int side = sqrt(board.size());
  for(int i = 0; i < board.size();i++){
    if(i % side == 0){
      cout << endl;
    }
    cout.width(3);
    cout << board[i];
    
  }
  cout << endl;
}

bool solveBoard(board_t board, int limit){
  //cout << limit << endl;
  if(isDone(board) || limit <= 0){
    printBoard(board);
    return true;
  }
  vector<board_t> children = successors(board);
  for(int i = 0; i < children.size(); i++){
    if( solveBoard(children[i],limit - 1) ){
      return true;
    }
  }
  return false;
}

int main(int argc, char* argv[]){
  if(argc < 3){
    cout << "Enter x y for starting knight\n";
    return 0;
  }
  int x = atoi(argv[1]);
  int y = atoi(argv[2]);
  board_t start;
  for(int i =0; i < BSIZE*BSIZE; i++){
    start.push_back(-1);
  }
  // Set night on board
  start[y * BSIZE + x] = 0;
  
  printBoard(start);
  
  solveBoard(start, 9999999);
}