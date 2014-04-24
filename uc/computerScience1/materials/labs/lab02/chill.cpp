/* Wind chill calculator.
 * CS1, lab2
 * Mike Helmick, mike.helmick@gmail.com
 */

#include <iostream>
#include <cmath>
using namespace std;

int main() {
  // Get user input
  cout << "Please enter a temperature in degrees farenheit: ";
  double tempF;
  cin >> tempF;
  cout << "Please enter the wind speed in MPH: ";
  double wind;
  cin >> wind;

  // Calculate wind chill
  double fWindChillNew = 35.74 + 0.6215 * tempF - 35.75 * pow(wind, 0.16) + 0.4275 * tempF * pow(wind, 0.16);
  double fWindChillOld = 0.0817 * (3.71 * sqrt(wind) + 5.81 - 0.25 * wind) * (tempF - 91.4) + 91.4;

  // Convert everything to C
  double tempC = (tempF - 32) * 5 / 9.0;
  double cWindChillNew = (fWindChillNew - 32) * 5 / 9.0;
  double cWindChillOld = (fWindChillOld - 32) * 5 / 9.0;

  cout << "Temp: " << round(tempF) << " degrees Farenheit: " << endl;
  cout << " new wind chill formula: " << round(fWindChillNew) << endl;
  cout << " old wind chill formula: " << round(fWindChillOld) << endl;
  cout << "Temp: " << round(tempC) << " Centigrade: " << endl;
  cout << " new wind chill formula: " << round(cWindChillNew) << endl;
  cout << " old wind chill formula: " << round(cWindChillOld) << endl;
}
