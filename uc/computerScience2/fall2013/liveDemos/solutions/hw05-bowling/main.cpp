#include <Game.h>
#include <GameRec.h>

#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void printStats(ofstream &outFile, vector<Game*> &games) {
  unsigned long rollTotal = 0;
  unsigned long pinTotal = 0;
  unsigned long strikeTotal = 0;
  unsigned int maxScore = 0;
  unsigned int minScore = 301;
  unsigned long averageScore = 0;
  unsigned int handicap = 0;

  for (vector<Game*>::iterator it = games.begin(); it != games.end(); it++) {
    rollTotal += (*it)->getRollCount();
    pinTotal += (*it)->getPinsKnockedDown();
    strikeTotal += (*it)->getStrikesThrown();

    long curScore = (*it)->getCurrentScore();
    if (curScore > maxScore) {
      maxScore = curScore;
    }
    if (curScore < minScore) {
      minScore = curScore;
    }
    averageScore += curScore;
  }
  averageScore /= games.size();
  handicap = round((210 - averageScore) * 0.90);

  outFile << "---- Your Statistics ----" << endl;
  outFile << "Total games played: " << games.size() << endl;
  outFile << "Total balls rolled: " << rollTotal << endl;
  outFile << "Total pins knocked down: " << pinTotal << endl;
  outFile << "Total strikes thrown: " << strikeTotal << endl;
  outFile << "Highest game score: " << maxScore << endl;
  outFile << "Lowest game score: " << minScore << endl;
  outFile << "Average score: " << averageScore << endl;
  outFile << "Handicap: " << handicap << endl;
}

// After this function ends, the caller owns the member pointed to in the games vector.
void readInGames(ifstream &inFile, ofstream &outFile, vector<Game*> &games) {
  string line = "";
  while (!inFile.eof()) {
    getline(inFile, line);
    
    // GameRec is recursive version.
    Game* game = new Game(); // new GameRec();
    for (unsigned int i = 0; i < line.size(); i += 2) {
      char roll = line[i];
      game->addRoll(roll);
      outFile << roll << " ";
    }
    
    if (game->isComplete()) {
      games.push_back(game); 
      outFile << ":: " << game->getCurrentScore() << endl;
    }
    // Don't need to clean up the game pointer, it is now owned by the vector.
    // It will need to be cleaned up before the program ends.
  }
}

int main(int argc, const char* argv[]) {
  if (argc != 3) {
    cout << "input filename is needed" << endl;
  }
  
  ifstream inFile;
  inFile.open(argv[1], ios::in);
  ofstream outFile;
  outFile.open(argv[2], ios::out);

  vector<Game*> games;
  readInGames(inFile, outFile, games);
  printStats(outFile, games);
  
  inFile.close();
  outFile.close();

  // Clean up dynamically allocated memory.
  for (unsigned int i = 0; i < games.size(); i++) {
    delete games[i];
    games[i] = NULL;
  }
  return 0;
}
