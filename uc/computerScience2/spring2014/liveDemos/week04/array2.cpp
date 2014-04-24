#include <iostream>
#include <cstdlib>
using namespace std;

void printArr(int* theArray, int size) {
  cout << "theArray: " << theArray << endl;

  for (int i = 0; i < size; i++) {
    cout << theArray[i] << " ";
  }
  cout << endl;
}

int main(int argc, char* argv[]) {
  if (argc != 3) {
    cout << "You must specify a size, like ./a.out 5" << endl;
    return 1;
  } 

  int iter = atoi(argv[1]);
  int size = atoi(argv[2]);
  int* myArr = NULL;

  for (int j = 0; j < iter; j++) {
    myArr = new int[size];

    for (int i = 0; i < size; i++) {
      myArr[i] = i;
    }
    //cout << "myArr: " << myArr << endl;
    //printArr(myArr, size);

    delete[] myArr;
    myArr = NULL;
  }

}

