// Conway's game of life.
// Add your name, etc here.
//
#include <cstdlib>
#include <iostream>
#include <unistd.h>
using namespace std;

const char DEAD = '.';
const char ALIVE = 'O';


int main(int argc, char* argv[]) {
  // Default generations to run is 100, but allow the user
  // to pass in a different value on the command line. Example:
  // ./a.out 50
  int generationsToRun = 100;
  if (argc > 1) {
    generationsToRun = atoi(argv[1]);
  }
  // ----- start of your program -----
   
  cout << "Generations to run: " << generationsToRun << endl;

}
