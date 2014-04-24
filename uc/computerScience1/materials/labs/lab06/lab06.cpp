#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

// Sentinel value for file end
const int ENDING = -1;
// Size of the array for vampire numbers
const int VAMPIRE_SIZE = 4;
// Size of the array for X largest
const int LARGEST = 10;

// Returns true if a number is even
bool isEven(int num) {
  return num % 2 == 0;
}

// Returns true if the number is not even
bool isOdd(int num) {
  return !isEven(num);
}

// Returns true if a number is prime.
bool isPrime(int num) {
  bool prime = true;
  int half = (int) (sqrt(num) + 2);
  // Loop from 2 to ~half, really the sqart + slop.
  for (int i = 2; i < half && prime; i++) {
    // If the number is evenly divisible, we can clearly say this is NOT
    // a prime number, so we will exit.
    prime = num % i != 0;    
  }
  // prime knows the answer for sure.
  return prime;
}

// Returns true if the number passed in is a vampire number.
bool isVampire(int num) {
  stringstream ss;
  ss << num;
  string numStr = ss.str();

  // We only work on 4 digit numbers
  if (numStr.size() != VAMPIRE_SIZE) {
    return false;
  }

  // Copy the characters into an array of int that contains
  // the 4 digits as an array of 4 ints (all single digit).
  int numS[VAMPIRE_SIZE];
  for (int i = 0; i < VAMPIRE_SIZE; i++) {
    numS[i] = numStr[i] - '0';
  }

  // Cheap way to put all combinations of 2 fangs
  // i and j are the indices of candidate fang 1
  // x and y are the indices of candidate fang 2
  for (int i = 0; i < VAMPIRE_SIZE; i++) {
    for (int j = 0; j < VAMPIRE_SIZE; j++) {
      if (i == j) {
        // i and j can't be the same, advance j
        continue;
      }

      for (int x = 0; x < VAMPIRE_SIZE; x++) {
        for (int y = 0; y < VAMPIRE_SIZE; y++) {
          if (x == y) {
            // x and y can't be the same, advance y
            continue;
          }

          if (x == i || x == j || y == i || y == j) {
            // none of the values can be the same,
            // advance y
            continue;
          }
          
          if (numS[j] == 0 && numS[y] == 0) {
            // both fangs cannot end in zero.
            continue;
          }

          // Compute the fang (digit 1 * 10) + digit 2
          int fang1 = numS[i] * 10 + numS[j];
          int fang2 = numS[x] * 10 + numS[y];
          if (fang1 * fang2 == num) {
            // We found one!
            return true;
          }
        }
      }
    }
  }
  // If we get here, we didn't find 2 fangs that work, return false.
  return false;
}

// If applicable, adds a number to the array holding the currently
// known 10 largest.
void addToLargest(int largest[], int size, int value) {
  // For each position in the X largest. Try and insert value
  for (int i = 0; i < size; i++) {
    // If value is > current thing at largest[i]
    if (value > largest[i]) {
      // Swap value w/ that and continue checking the rest of the array
      // with the new value (what was swapped out of largest[i])
      int tmp = largest[i];
      largest[i] = value;
      value = tmp;
    }
  }  
}

int main() {
  // Open all files
  ifstream inFile;
  inFile.open("input.txt");

  ofstream evenFile;
  evenFile.open("evens.txt");
  ofstream oddFile;
  oddFile.open("odds.txt");
  ofstream primeFile;
  primeFile.open("primes.txt");
  ofstream vampFile;
  vampFile.open("vampires.txt");

  // Declare counters
  int numCount = 0;
  int primeCount = 0;
  int evenCount = 0;
  int oddCount = 0;
  int vampireNumbers = 0;

  // Initialze the "largest" array to all zeros.
  int tenLargest[LARGEST];
  for (int i = 0; i < LARGEST; i++) {
    tenLargest[i] = 0;
  }

  // Main processing loop.
  int val;
  inFile >> val;
  while (val != ENDING) {
    if (isEven(val)) {
      evenCount++;
      evenFile << val << endl;
    }
    if (isOdd(val)) {
      oddCount++;
      oddFile << val << endl;
    }
    if (isPrime(val)) {
      primeCount++;
      primeFile << val << endl;
    }
    if (isVampire(val)) {
      vampireNumbers++;
      vampFile << val << endl;
    }
    addToLargest(tenLargest, LARGEST, val);

    numCount++;
    inFile >> val;
  }

  // Basic output stats.
  cout << "Numbers read in: " << numCount << endl;
  cout << "Even numbers: " << evenCount << endl;
  cout << "Odd numbers: " << oddCount << endl;
  cout << "Prime numbers: " << primeCount << endl;
  cout << "Vampire numbers: " << vampireNumbers << endl;
  cout << "Ten largest numbers:" << endl;
  for (int i = 0; i < LARGEST; i++) {
    cout << "  - " << tenLargest[i] << endl;
  }

  inFile.close();
  evenFile.close();
  oddFile.close();

  return 0;
}
