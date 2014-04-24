#include <iostream>
using namespace std;

int main() {

  int sum = 0;
  int arr[] = {4, 5, 6, 7}; 

  for (int i = 0; i < 4; i++) {
    sum += arr[i];
  } 
  cout << "sum = " << sum << endl;

}
