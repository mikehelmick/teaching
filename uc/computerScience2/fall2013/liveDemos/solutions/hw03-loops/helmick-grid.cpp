/**   @file grid.cpp    
      @author Mike Helmick
      @date 09-20-2013
      
      This program asks the user for the dimensions of a grid, then prints the 
      board to the screen using ASCII characters: +, |, and -.    
      */

#include <iostream>
#include <string>

using namespace std;

void calculatePoints(const string& direction, int span, bool* points, int divisions) {
  for (int i = 0; i < span; i++) {
    points[i] = false;
  }
  // First and last are on
  points[0] = true;
  points[span - 1] = true;

  int divLeft = divisions - 1;
  // Span - outer borders - # of desired borders  
  int pointsLeft = span - 2 - divLeft;

  if (pointsLeft < 0) {
    cout << endl << "More " << direction << " were asked for than possible, enjoy your output." << endl;
    // There were more divisions asked for than are possible, all points on.
    for (int i = 0; i < span; i++) {
      points[i] = true;
    }
    return;
  }

  // There is at least some room to draw points.
  int spacesForEach = pointsLeft / divisions;
  // If it doesn't divide evenly, the extra spaces are distributed to the first few columns
  int extraSpaces = pointsLeft % divisions;
  // Go turn on the points.
  int idx = 1; // zero is the border, so starting at 1 intentionally
  while (divLeft > 0) {
    idx = idx + spacesForEach;
    if (extraSpaces > 0) {
      idx++;
      extraSpaces--;
    }
    points[idx] = true;
    idx++; // move to the next space
    divLeft--;
  }
}

void printGrid(int width, int height, const bool* xVals, const bool* yVals) {
  cout << endl;
  // For each line, row
  for (int y = 0; y < height; y++) {
    // For each column
    for (int x = 0; x < width; x++) {
      if (yVals[y]) {
        // We're on a horizontal line
        if (xVals[x]) {
          // And also on a vertical line
          cout << "+";
        } else {
          cout << "-";
        }
      } else if (xVals[x]) {
        // not on a horizontal line, but on a vertical line
        cout << "|";
      } else {
        // Not on any line.
        cout << " ";
      }
    }
    // Done writing this line.
    cout << endl;  
  }
}


int main(){
  cout << "Enter your desired width and height of the board in characters, separated by a space.:";
  int width;
  int height;
  cin >> width;
  cin >> height;
 
  cout << "\nHow many columns and rows do you want?  Separate by a space.:";
  int cols;
  int rows;
  cin >> cols;
  cin >> rows;

  // Allocate pointers to the vlalues that are "on"
  bool* xVals = new bool[width];
  bool* yVals = new bool[height];
  calculatePoints("columns", width, xVals, cols);
  calculatePoints("rows", height, yVals, rows);
  printGrid(width, height, xVals, yVals);

  // Deallocate memory
  delete xVals;
  xVals = NULL;
  delete yVals;
  yVals = NULL;
  return 0;
}
