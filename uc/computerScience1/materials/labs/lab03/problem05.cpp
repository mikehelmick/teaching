#include <iostream>
using namespace std;

const int SECONDS_IN_DAY = 86400;
const int SECONDS_IN_HOUR = 3600;
const int SECONDS_IN_MINUTE = 60;

int countUnit(int &seconds, int width) {
  int unitCount = 0;
  while (seconds > width) {
    unitCount++;
    seconds -= width;
  }
  return unitCount;
}

int main() {

  int seconds = 0;
  while (seconds <= 0) {
    cout << "Enter the number of seconds: ";
    cin >> seconds;
    if (seconds <= 0) {
      cout << "ERROR: The number of seconds must be a positive number." << endl;
    }
  }
  
  char type = 'x';
  while (!(type == 'm' || type == 'h' || type == 'd')) {
    cout << "Do you want this converted to (m)inutes, (h)ours, or (d)ays? ";
    cin >> type;
    if (!(type == 'm' || type == 'h' || type == 'd')) {
      cout << "ERROR: you must enter m, h, or d." << endl;
    }
  }

  if (type == 'd') {
    int days = countUnit(seconds, SECONDS_IN_DAY);
    int hours = countUnit(seconds, SECONDS_IN_HOUR);
    int minutes = countUnit(seconds, SECONDS_IN_MINUTE);
    cout << days << " days, " << hours << " hours, " << minutes << " minutes, and "
        << seconds << " seconds." << endl;
  } else if (type == 'h') {
    int hours = countUnit(seconds, SECONDS_IN_HOUR);
    int minutes = countUnit(seconds, SECONDS_IN_MINUTE);
    cout << hours << " hours, " << minutes << " minutes, and "
        << seconds << " seconds." << endl;
  } else {
    int minutes = countUnit(seconds, SECONDS_IN_MINUTE);
    cout << minutes << " minutes, and " << seconds << " seconds." << endl;
  }

  return 0;
}