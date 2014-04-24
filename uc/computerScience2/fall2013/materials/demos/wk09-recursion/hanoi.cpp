#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

struct game_t{
  vector<int> A;
  vector<int> B;
  vector<int> C;
};

void printGame(game_t game){
  cout << "A:";
  for(int i = 0; i < game.A.size();i++){
    cout << game.A[i] << " ";
  }
  cout << "\nB:";
  for(int i = 0; i < game.B.size();i++){
    cout << game.B[i] << " ";
  }
  cout << "\nC:";
  for(int i = 0; i < game.C.size();i++){
    cout << game.C[i] << " ";
  }
  cout << endl << endl;
}

void doMove(char from, char to, game_t& game){
  vector<int>* f;
  vector<int>* t;
  if(from == 'A')f = &game.A;
  else if(from == 'B')f = &game.B;
  else if(from == 'C')f = &game.C;
  else{ 
    cout << "ERROR FROM! " << from << " -> " << to << endl;
    printGame(game);
    return;
  }
  if(to == 'A')t = &game.A;
  else if(to == 'B')t = &game.B;
  else if(to == 'C')t = &game.C;
  else{ 
    cout << "ERROR TO! " << from << " -> " << to << endl;
    printGame(game);
    return;
  }
  t->push_back((*f)[f->size()-1]);  // copy top of from to to
  f->erase(f->end()-1);
}

void hanoi(int level, char source, char dest, char other, game_t& game){
  if( level == 1){
    cout << "Move from " << source << " to " << dest << endl;
    doMove(source,dest,game);
    printGame(game);
  }else{
    // Move all disks on top of level on source to other
    hanoi(level - 1, source, other, dest, game);
    // Move one we want
    cout << "Move from " << source << " to " << dest << endl;
    doMove(source,dest,game);
    printGame(game);
    // Put them back
    hanoi(level - 1, other, dest, source, game);
    
  }
} 

int main(int argc, char* argv[]){
  game_t game;
  game.A.push_back(5);
  game.A.push_back(4);
  game.A.push_back(3);
  game.A.push_back(2);
  game.A.push_back(1);
  
  printGame(game);

  
  hanoi(5,'A','B','C', game);
}