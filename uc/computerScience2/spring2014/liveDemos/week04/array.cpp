#include <iostream>
using namespace std;

void printArr(int* theArray, int size) {
  cout << "theArray: " << theArray << endl;

  for (int i = 0; i < size; i++) {
    cout << "theArray[" << i << "]: " << theArray[i] << endl;
    cout << "*(theArray + i): " << *(theArray + i) << endl;
    cout << "&theArray[" << i << "]: " << &(theArray[i]) << endl;
    cout << "*(&(theArray[" << i << "])): " << *(&(theArray[i])) << endl;
  }
}

int main() {

  int myArr[10];

  for (int i = 0; i < 10; i++) {
    myArr[i] = i;
  }
  cout << "myArr: " << myArr << endl;
  printArr(myArr, 10);

   

}

