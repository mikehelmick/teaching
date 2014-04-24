#include <IMonopoly.h>
#include <Monopoly.h>

#include <time.h>
#include <cstdlib>

using namespace std;

/**
 * Monopoly simulation
 *
 * Author: Mike Helmick - mike.helmick@uc.edu
 */
int main(int argc, char* argv[]) {
  // Mandatory args
  int players = atoi(argv[1]);
  int rounds = atoi(argv[2]);
  
  // Handle optional arguments.
  if (argc >= 4) {
    srand(atoi(argv[3]));
  } else {
    srand(time(NULL));
  }
  bool verbose = false;
  if (argc >= 5) {
    string arg4(argv[4]);
    verbose = "-v" == arg4;
  }
 
  IMonopoly* game = new Monopoly(players, rounds);
  game->simulate(verbose);
  cout << endl << game->getResults() << endl;
  delete game;
}
