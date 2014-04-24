#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
  string product1 = "A Book";
  string product2 = "DVD Boxed Set";
  string product3 = "This is a product with long name";

  int quantity1 = 2;
  int quantity2 = 12;
  int quantity3 = 25233;

  cout << "Your Invoice:" << endl;
  cout << setw(25) << product1 << "Qty: " << setw(4) << quantity1 << endl;
  cout << setw(25) << product2 << "Qty: " << setw(4) << quantity2 << endl;
  cout << setw(25) << product3 << "Qty: " << setw(4) << quantity3 << endl;
}