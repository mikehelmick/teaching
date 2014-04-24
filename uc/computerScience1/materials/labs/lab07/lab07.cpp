#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

struct Product {
  string name;
  float price;
  float reviews;
};

void printProducts(Product products[], int size) {
  for (int i = 0; i < size; i++) {
    cout << "$" << setw(7) << setprecision(2) << fixed << products[i].price
        << setw(5) << setprecision(1) << products[i].reviews << " stars: "
        << products[i].name << endl;
  }
}

void sortByReview(Product arr[], int size) {
  bool sorted = false;
  int upTo = size - 1;
  while (!sorted) {
    sorted = true; // Assume we will sort it this time!
    for (int i = 0; i < upTo; i++) {
      if (arr[i].reviews < arr[i + 1].reviews) {
        Product temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
        sorted = false;
      }
    }
    upTo--;
  }
}

void sortByPrice(Product arr[], int size) {
  for (int i = 0; i < size - 1; i++) {
    int point = i;
    for (int j = i + 1; j < size; j++) {
      if (arr[j].price < arr[point].price) {
        point = j;
      }
    }
    if (point != i) {
      Product temp = arr[i];
      arr[i] = arr[point];
      arr[point] = temp;
    }
  }
}

int main() {
  ifstream inFile;
  inFile.open("products.txt");

  string line;
  getline(inFile, line);
  int size = atoi(line.c_str());

  Product products[size];
  for (int i = 0; i < size; i++) {
    getline(inFile, line);
    products[i].name = line;

    getline(inFile, line);
    products[i].price = atof(line.c_str());

    getline(inFile, line);
    products[i].reviews = atof(line.c_str());
  }
  inFile.close();

  cout << "Popular tables:" << endl;
  printProducts(products, size);

  char choice = 's';
  while (choice != 'q') {
    cout << "Sort by price ('p'), review ('r'), or quit ('q')? ";
    cin >> choice;
    while (!(choice == 'q' || choice == 'r' || choice == 'p')) {
      cout << "Please enter 'p', 'r', or 'q': " << endl;
      cin >> choice;
    } 

    if (choice == 'p') {
      cout << endl << "Sorted by price:" << endl;
      sortByPrice(products, size);
      printProducts(products, size);
    } else if (choice == 'r') {
      cout << endl << "Sorted by review:" << endl;
      sortByReview(products, size);
      printProducts(products, size);
    }
  } 
  return 0;
}
