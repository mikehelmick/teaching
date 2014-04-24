#include <iostream>

using namespace std;

const int SIZE = 10;

void printTable(int table[SIZE][SIZE]) {
 for (int i = 0; i < SIZE; i++) {
   for (int j = 0; j < SIZE; j++) { 
     cout << table[i][j] << " ";
   }
   cout << endl;
 }
}

int main() {
  int table[SIZE][SIZE];

  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      table[i][j] = i * j;
    }
  }
  printTable(table);

}
