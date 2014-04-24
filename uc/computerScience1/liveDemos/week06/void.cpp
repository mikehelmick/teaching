#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void displayDollars(string message, double amount) {
  cout << setw(20) << message << ": $"
      << setw(11) << setprecision(2) << fixed << amount << endl;
}

int main() {
   double balance = 100.25;
   double addition = 5.25;

   displayDollars("Starting balance", balance);
   for (int i = 0; i < 10; i++) {
     displayDollars("Adding", addition);
     balance += addition;
     displayDollars("Account Balance", balance);
     addition += addition * i;
   }
}
