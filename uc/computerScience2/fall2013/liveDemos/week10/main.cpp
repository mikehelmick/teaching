#include <iostream>

using namespace std;

void print(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

void sort(int arr[], int size) {
  for (int fill = 0; fill < size - 1; fill++) {
    int posMin = fill;
    for (int next = fill + 1; next < size; next++) {
      if (arr[next] < arr[posMin]) {
        posMin = next;
      }
    }
    // I know that posMin is the element that belongs
    // at a[fill].
    if (posMin != fill) {
      int tmp = arr[fill];
      arr[fill] = arr[posMin];
      arr[posMin] = tmp;
    }
    print(arr, size);
  }
}

void test() {
  int a[] = {1, 1, 1, 1, 1};
  sort(a, 5);
  
  for(int i = 0; i < 5 - 1; i++) {
    TS_ASSERT(a[i] <= a[i+1]);
  }
}

int main() {
  int a[] = {4, 6, 2, 7, 8, 0};
  int size =6;
  
  print(a, size);
  sort(a, size);
}


