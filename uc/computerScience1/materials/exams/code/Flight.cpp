#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Flight {
public:
  Flight(string airline, int number, string origin, string destination) {
    this->airline = airline;
    this->number = number;
    this->origin = origin;
    this->destination = destination;
  }

  string getAirline() { return airline; }
  void setAirline(string newAirline) {
    airline = newAirline;
  }
  int getFlightNumber() { return number; }
  void setFlightNumber(int newNumber) {
    number = newNumber;
  }
  string getOriginCity() { return origin; }
  void setOriginCity(string city) {
    origin = city;
  }
  string getDestinationCity() { return destination; }
  void setDestinationCity(string city) {
    destination = city;
  }
  
private:
  string airline;
  int number;
  string origin;
  string destination;
};

int main() {
  
}