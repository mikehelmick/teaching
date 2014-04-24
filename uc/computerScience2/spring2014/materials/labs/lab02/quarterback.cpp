/**
 * A program to calculate the quarterback rating.
 */
#include <iostream>
using namespace std;

// Reads in the number of completions
int getCompletions() {
  cout << "Enter the number of completions: ";
  int completions = 0;
  cin >> completions;
  return completions;
}

int getAttempts() {
  cout << "Enter the number of attempts: ";
  int attempts = 0;
  cin >> attempts;
  return attempts;
}

int getYards() {
  cout << "Enter the number of yards: ";
  int yards = 0;
  cin >> yards;
  return yards;
}

int getInterceptions() {
  cout << "Enter the number of interceptions: ";
  int interceptions = 0;
  cin >> interceptions;
  return interceptions;
}

int getTouchdowns() {
  cout << "Enter the number of touchdowns: ";
  int touchdowns = 0;
  cin >> touchdowns;
  return touchdowns;
}

double calculateCompletionPercentage(int completions, int attempts) {
  return (((double)completions / attempts) - 0.3) * 5;
}

double calculateTdPercentage(int touchdowns, int attempts) {
  return ((double)touchdowns / attempts) * 20;
}

double calculateYardsPerAttemps(int yards, int attempts) {
  return ((double)yards / attempts - 3.0) * 0.25;
}

double calculateInterceptionPercentage(int interceptions, int attempts) {
  return 2.375 - (double)interceptions / (4 * (double) attempts) * 100.0;
}

void normalize(double &value) {
  if (value < 0) {
    value = 0;
  } else if (value > 2.375) {
    value = 2.375;
  }
}

double qbRating(double completionPercentage, double tdPercentage,
    double yardsPerAttempt, double interceptionPct) {
  return (completionPercentage + tdPercentage + yardsPerAttempt + interceptionPct)
    / 6 * 100;
}

int main() {
  // Read in the user input.
  int completions = getCompletions();  
  // TODO(you): Step 1, Read in the other elements, with a function for each.
  int attempts = getAttempts();
  int yards = getYards();
  int interceptions = getInterceptions();
  int touchdowns = getTouchdowns();

  // TODO(you): Step 2, Compute the derived values.
  double completionPercentage = calculateCompletionPercentage(completions, attempts);
  double tdPercentage = calculateTdPercentage(touchdowns, attempts);
  double yardsPerAttempts = calculateYardsPerAttemps(yards, attempts);
  double interceptionPct = calculateInterceptionPercentage(interceptions, attempts);
  
  cout << "  CompletionPct " << completionPercentage << endl;
  cout << "YardsPerAttempt " << yardsPerAttempts << endl;
  cout << "   TDPercentage " << tdPercentage << endl;
  cout << "InterceptionPct " << interceptionPct << endl;
  
  // TODO(you): Step 3, Normalizee the derived values.
  normalize(completionPercentage);
  normalize(tdPercentage);
  normalize(yardsPerAttempts);
  normalize(interceptionPct);
  
  cout << "normalized" << endl;
  cout << "  CompletionPct " << completionPercentage << endl;
  cout << "YardsPerAttempt " << yardsPerAttempts << endl;
  cout << "   TDPercentage " << tdPercentage << endl;
  cout << "InterceptionPct " << interceptionPct << endl;
  
  // TODO(you): Step 4, compute the quarterback rating
  double rating = qbRating(completionPercentage, tdPercentage,
      yardsPerAttempts, interceptionPct);
  cout << "QB Rating: " << rating << endl;
  return 0;
}