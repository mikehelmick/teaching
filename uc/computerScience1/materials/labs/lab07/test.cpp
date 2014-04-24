#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

struct Product {
  string name;
  float price;
  float reviews;
};

void printProducts(Product products[], int size) {
  for (int i = 0; i < size; i++) {
    cout << "$" << setw(7) << setprecision(2) << fixed << products[i].price
        << setw(10) << setprecision(1) << products[i].reviews << " stars: "
        << products[i].name << endl;
  }
}

int main() {
  ifstream inFile;
  inFile.open("products.txt");

  int size;
   
  while(!inFile.eof()) {
    string line;
    getline(inFile, line);
    cout << line << endl;
  }
  return 0;
}
