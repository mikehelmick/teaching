#include <iostream>
#include <string>

#include <Person.h>

using namespace std;

void printChart(int steps) {
  int stars = steps / 10;
  for (int i = 0; i < stars; i++) {
    cout << "*";
  }
  cout << endl;
}

int main(int argc, char* argv[]) {
  Person p;

  // Loop variables  
  string direction = "";
  int steps = 0;

  while (true) {
    cout << "You are now at (" << p.getXPos() << "," << p.getYPos() << ")" << endl;
    cout << "Total steps taken: " << p.getSteps() << " ";
    printChart(p.getSteps());
    cout << "Enter the direction to travel ('exit' to quit)" << endl;
    cin >> direction;
    if (direction == "exit") {
      break;
    }

    cout << "Enter the number of steps" << endl;
    cin >> steps;

    if (!p.move(direction, steps)) {
      cout << "Error: Invalid direction (N, S, E, W, NE, NW, SE, SW) or number of steps (>= 1)." << endl;
    }
  }
  
  cout << "Final position: " << p.getXPos() << "," << p.getYPos() << ")" << endl;
  cout << "Total steps taken: " << p.getSteps() << " ";
  printChart(p.getSteps());
  
  return 0;
}