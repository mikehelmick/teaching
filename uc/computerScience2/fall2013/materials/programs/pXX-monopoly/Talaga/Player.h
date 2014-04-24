#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <queue>

#include "Die.h"

using namespace std;

struct board_t{
	int* boardCnt;
	vector<string>* board;
	queue<string>* chest;
	queue<string>* chance;
};

// Notable places on the board
const int JAIL = 10;
const int COM1 = 2;
const int CHA1 = 7;
const int COM2 = 17;
const int CHA2 = 22;
const int GOTO = 30;
const int COM3 = 33;
const int CHA3 = 36;
const int ILL  = 24;
const int CHAR = 11;
const int ELEC = 12;
const int WATE = 28;
const int READ = 5;
const int BOAR = 39;

class Player{
public:
	Player(int num, board_t* board, bool verbose);
	
	void doTurn();
	int getPosition();
	
	bool hasChanceJail();
	bool hasChestJail();
	
	int getName();
	
private:
	
	int name;
	int location;
	string hasGetOutOfJailChance;
	string hasGetOutOfJailChest;
	
	int jailState;
	int doubleRollCnt;
	
	bool verbose;
	
	board_t* board;
	
	Player();
};


#endif