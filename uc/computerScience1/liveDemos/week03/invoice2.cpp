#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
  string product1 = "A Book";
  string product2 = "DVD Boxed Set";

  int quantity1 = 2;
  int quantity2 = 12;
  
  double unitPrice1 = 6.98;
  double unitPrice2 = 45.99;
  
  double totalPrice1 = quantity1 * unitPrice1;
  double totalPrice2 = quantity2 * unitPrice2;

  cout << "Your Invoice:" << endl;
  cout << setw(25) << left << "Product" << " Quantity   "
    << setw(12) << "Unit Price"
    << "  "
    << setw(15) << "Total Price" << endl << right;
  cout << setw(25) << product1 << setw(9) << quantity1
    << "   $" << setw(10) << setprecision(2) << fixed << unitPrice1 
    << "   $" << setw(10) << totalPrice1 << endl;
  cout << setw(25) << product2 << setw(9) << quantity2
    << "   $" << setw(10) << setprecision(2) << fixed << unitPrice2 
    << "   $" << setw(10) << totalPrice2 << endl;

  cout << setw(10) << setprecision(2) << fixed << 45.2 << endl;
}