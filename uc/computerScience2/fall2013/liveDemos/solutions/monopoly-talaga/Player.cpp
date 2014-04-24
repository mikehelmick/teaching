#include <string>
#include <iostream>
#include <queue>
#include <cstring>

#include "Player.h"
#include "Die.h"

using namespace std;

Player::Player(int num, board_t* board, bool verbose){
	name = num;
	this-> board = board;
	location = 0;
	hasGetOutOfJailChance = "";//"Get Out of Jail Free";
	hasGetOutOfJailChest = "";//"Get Out of Jail Free";
	this->verbose = verbose;
	jailState = 0;
	doubleRollCnt = 0;
}

int Player::getPosition(){
	return location;
}

int Player::getName(){
	return name;
}

bool Player::hasChanceJail(){
	return hasGetOutOfJailChance.length() > 0;
}

bool Player::hasChestJail(){
	return hasGetOutOfJailChest.length() > 0;
}

void Player::doTurn(){
	Die d;
	int move = d.roll();
  if (verbose) {
    cout << "Player " << name << " rolls " << d.getD1() << "+" << d.getD2() << endl;
  }
  
	// Did we roll doubles too much?
	if(d.wasDoubles() && doubleRollCnt >= 2){
		// go to jail!
		location = JAIL;
		board->boardCnt[location]++;
		jailState = 2;
		if(verbose){
			cout << "Player " << name << " rolled 3 doubles, go to jail.\n";
		}
		return;
	}
	
	bool wasInJail = false;
	// Are we in jail?
	if(jailState != 0){	 // YES
		// Do I have a get out of jail free card?
		if(hasGetOutOfJailChance.length() > 0){
			// put the card back
			board->chance->push(hasGetOutOfJailChance);
			hasGetOutOfJailChance = "";
			jailState = 0;
			if(verbose)cout << "Used Chance GetOutOfJail card!\n";
		}else if(hasGetOutOfJailChest.length() > 0){
			// put the card back
			board->chest->push(hasGetOutOfJailChest);
			hasGetOutOfJailChest = "";
			jailState = 0;
			if(verbose)cout << "Used Chest GetOutOfJail card!\n";
		}else{
			// did we get a double?
			if(!d.wasDoubles()){	// No?
				jailState--;
				if(verbose) {
          cout << " - still in jail" << endl;
          // cout << "Rolled a " << move << " not doubles. ;-(\n";
        }          
				return;
			}else{ // We rolled doubles!
				if(verbose) {
          cout << " - doubles, releasing from jail." << endl;
          //cout << "Rolled DOUBLES!!!!";
        }
				jailState = 0;
				//wasInJail = true; // This would prevent rolling again with doubles
			}
		}
		
	}
	// Now we're not in jail
	location = (location + move ) % 40;
	
	if(verbose){
    cout << "Player " << name << " landed on " << board->board->at(location) << endl;
		//cout << "Landed on " << board->board->at(location) << " with a " << move; 
		if(d.wasDoubles() && !wasInJail){
			// cout << " DOUBLES";
		}
		//cout << endl;
	}
	
	// update square count
	board->boardCnt[location]++;
	
	// Do whatever that square needs -------------------
	
	// Laned on 'GO TO JAIL'
	if(location == GOTO){
		// go to jail!
		location = JAIL;
		board->boardCnt[location]++;
		jailState = 2;
		return; // prevent from rolling doubles
	}
	// Chance  need to do this first because it can move you
	if(location == CHA1 || location == CHA2 || location == CHA3){
		string card = board->chance->front();
		board->chance->pop();
		if(verbose){cout << " -> Chance - " << card << endl;}
		if(strcmp(card.c_str(),"Advance to Go") == 0){
			location = 0;
			board->boardCnt[location]++;
			board->chance->push(card); 	// put card back
		}else if(strcmp(card.c_str(),"Get Out of Jail Free") == 0){
			hasGetOutOfJailChance = card;
			// keep card!!!!!
		}else if(strcmp(card.c_str(),"Go to Jail") == 0){
			location = JAIL;
			board->boardCnt[location]++;
			jailState = 2;
			board->chance->push(card);
			return; // prevent from rolling doubles
		}else if(strcmp(card.c_str(),"Advance to Illinois Ave.") == 0){
			location = ILL;
			board->boardCnt[location]++;
			board->chance->push(card); 	// put card back
		}else if(strcmp(card.c_str(),"Advance to St. Charles Place") == 0){
			location = CHAR;
			board->boardCnt[location]++;
			board->chance->push(card); 	// put card back
		}else if(strcmp(card.c_str(),"Advance token to nearest Utility") == 0){
			if(location <= ELEC || location > WATE){		// Hopefully this math is ok.
				location = ELEC;	// Electric company
			}else{
				location = WATE; // Water works
			}
			board->boardCnt[location]++;
			board->chance->push(card); 	// put card back
		}else if(strcmp(card.c_str(),"Advance to nearest Railroad") == 0){
			//location = ((location + 5) / 10 + 5) % 40;
			if(location <=5 || location > 35){
				location = 5;
			}else if(location <= 15){
				location = 15;
			}else if(location <= 25){
				location = 25;
			}else{
				location = 35;
			}
			board->boardCnt[location]++;
			board->chance->push(card); 	// put card back
		}else if(strcmp(card.c_str(),"Take a ride on the Reading Railroad") == 0){
			location = READ;
			board->boardCnt[location]++;
			board->chance->push(card); 	// put card back
		}else if(strcmp(card.c_str(),"Advance token to Boardwalk") == 0){
			location = BOAR;
			board->boardCnt[location]++;
			board->chance->push(card); 	// put card back
		}else if(strcmp(card.c_str(),"Go back 3 spaces") == 0){
			location = location - 3;
			board->boardCnt[location]++;
			board->chance->push(card); 	// put card back
		}else{
			// must not be a special card, return to deck
			board->chance->push(card); 	// put card back
		}
	}
	
	// Community chest
	if(location == COM1 || location == COM2 || location == COM3){
		string card = board->chest->front();
		board->chest->pop();
		if(verbose){cout << " -> Community Chest - " << card << endl;}
		if(strcmp(card.c_str(),"Advance to Go") == 0){
			location = 0;
			board->boardCnt[location]++;
			board->chest->push(card); 	// put card back
		}else if(strcmp(card.c_str(),"Get Out of Jail Free") == 0){
			hasGetOutOfJailChest = card;
			// keep card!!!!!
		}else if(strcmp(card.c_str(),"Go to Jail") == 0){
			location = JAIL;
			board->boardCnt[location]++;
			jailState = 2;
			board->chest->push(card);
			return; // prevent from rolling doubles
		}else{ // Don't care about anything else, return card
			board->chest->push(card);
		}
		
	}
	
	// did we have doubles?
	if(d.wasDoubles() && !wasInJail){
		doubleRollCnt++;
		doTurn();
	}
	doubleRollCnt = 0;
}