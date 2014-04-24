#include <iostream>
using namespace std;


enum DayOfWeek {
  SUNDAY, // Default, 0
  MONDAY,
  TUESDAY,
  WEDNESDAY,
  THURSDAY,
  FRIDAY,
  SATURDY
};

void printDay(DayOfWeek day) {
  if (day == SUNDAY) {
    cout << "Sunday." << endl;
  }
}

int main() {
  DayOfWeek day = TUESDAY;
  cout << "TUESDAY is " << TUESDAY << endl;

  DayOfWeek nextDay = (DayOfWeek) (TUESDAY + 1);
  cout << "TUESDAY + 1 is " << nextDay << endl;

  DayOfWeek myDay = (DayOfWeek) 4;

  printDay(SUNDAY);
}
