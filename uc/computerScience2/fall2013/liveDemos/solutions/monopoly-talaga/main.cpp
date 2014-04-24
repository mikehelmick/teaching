#include <iostream>
#include <cstdlib>
#include <queue>
#include <vector>
#include <fstream>

#include "Die.h"
#include "Player.h"

using namespace std;

int main(int argc, char* argv[]){
	if(argc < 3){
		cout << "Enter the number of players and number of turns\n";
		return 1;
	}
	int numplayers = atoi(argv[1]);
	int turns = atoi(argv[2]);
	if(argc > 3){
		srand(atoi(argv[3]));
	}else{
		srand(time(0));
	}
	bool verbose = false;
	if(argc > 4 && strcmp(argv[4],"-v") == 0){
		verbose = true;
	}
	
	cout << "Num Players: " << numplayers << " Turns: " << turns << endl;
	cout << "Verbose: " << verbose << endl;
	
	// Load files
	int boardCnt[40];
	for(int i = 0; i < 40; i++){
		boardCnt[i] = 0;
	}
	vector<string> board;
	queue<string> chest;
	queue<string> chance;
	
	// Load board ---------------------------
	ifstream foo;
	foo.open("board.txt");
	if(foo.fail()){
		cout << "Could not open board.txt.\n";
		return 1;
	}
	string line;
	while(getline(foo, line)){
		board.push_back(line);
	}
	foo.close();
	
	// Load chance ---------------------------
	foo.open("chance.txt");
	if(foo.fail()){
		cout << "Could not open chance.txt.\n";
		return 1;
	}
	while(getline(foo, line)){
		chance.push(line);
	}
	foo.close();
	
	// Load chest ---------------------------
	foo.open("communitychest.txt");
	if(foo.fail()){
		cout << "Could not open communitychest.txt.\n";
		return 1;
	}
	while(getline(foo, line)){
		chest.push(line);
	}
	foo.close();
	
	
	
	queue<Player*> players;
	
	board_t boardState;
	boardState.boardCnt = boardCnt;	// the magic of pointers
	boardState.board = &board;
	boardState.chest =&chest;
	boardState.chance = &chance;
	
	// Make the players
	for(int i = 0; i < numplayers; i++){
		Player* p = new Player(i, &boardState, verbose);
		players.push(p);
	}
	
	// Run the game!
	for(int i = 0; i < turns; i++){
		if(verbose){
      cout << "++++++++++++++++++++" << endl;
      cout << "Starting round " << (i+1) << endl;
			//cout << "\nROUND " << i+1 << " -----Chess: " << chest.size() << " -----Chance: " << chance.size() << "------------------------------------------------------------" << endl;
		}
		for(int j = 0; j < numplayers; j++){
			Player* p = players.front();
			players.pop();
			if(verbose){
        // Player 0 starting on Go
        cout << "Player " << p->getName() << " starting on " << board[p->getPosition()] << endl;
        
				//cout << "Player: " << p->getName() << " at " << p->getPosition() << ": " <<board[p->getPosition()];
				//cout << "  ChanceJail: " << p->hasChanceJail() << "  ChestJail: " << p->hasChestJail() << endl;
			}
			p->doTurn();
			//if(verbose)cout << endl;
			players.push(p);
		}
	}
	
	// Print out stats
  cout << endl;
	for(int i = 0; i < 40; i++){
		cout << board[i] << " :: " << boardCnt[i] << endl;
	}
	return 0;
}