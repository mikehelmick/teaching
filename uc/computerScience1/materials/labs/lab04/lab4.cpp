#include<iostream>
#include<iomanip>

using namespace std;

const int ENDING_VALUE = -1;

int main() {
  cout << "This program will compute an automobile’s gas mileage statistics." << endl;

  cout << "Enter initial odometer reading: ";
  int odomStart = 0;
  cin >> odomStart;  // 5000

  int odometer = odomStart;
  double dollarsPaid = 0;
  int fillUpCount = 0;
  double totalGallons = 0;

  while (true) {
    cout << endl << "Fill-up #" << (fillUpCount + 1) << endl;
    cout << "Enter gallons used (negative number to end): ";
    double gallons = 0.0;
    cin >> gallons;
    
    if (gallons < 0) {
      break;
    }
    fillUpCount++;

    cout << "Enter price paid: $";
    double price;
    cin >> price;

    cout << "Enter new odometer reading: ";
    int newOdometer;
    cin >> newOdometer;

    cout << endl << "Stats for fill-up #" << fillUpCount << ":" << endl;
    int thisMiles = newOdometer - odometer;
    double mpg = thisMiles / gallons;
    double ppg = price / gallons;
    double mpd = thisMiles / price;
    
    cout << " * " << thisMiles << " miles" << endl;
    cout << " * " << setprecision(1) << fixed << mpg << " miles per gallon" << endl;
    cout << " * " << setprecision(2) << fixed << "$" << ppg << " per gallon" << endl;
    cout << " * " << setprecision(2) << fixed << mpd << " miles per dollar" << endl;
  
    // Update ending totals
    odometer = newOdometer;
    dollarsPaid += price;
    totalGallons += gallons;
  }
  
  cout << endl << "Final statistics: After " << fillUpCount << " fill-ups." << endl;
  int totalMiles = odometer - odomStart;
  double mpg = totalMiles / totalGallons;
  double ppg = dollarsPaid / totalGallons;
  double mpd = totalMiles / dollarsPaid;
  cout << " * " << totalMiles << " miles" << endl;
  cout << " * " << setprecision(1) << fixed << mpg << " miles per gallon" << endl;
  cout << " * " << setprecision(2) << fixed << "$" << ppg << " per gallon" << endl;
  cout << " * " << setprecision(2) << fixed << mpd << " miles per dollar" << endl;
  
  cout << endl << "Goodbye!" << endl;
}


