#include <iostream>

using namespace std;

int main(){
  int* temp = NULL;
  int* t2 = new int;
  for(int i = 0; i < 2; i++){
    cout << temp << endl;
    temp = new int[10000];
    cout << "0:" << temp[0] << endl;
    temp[0] = 1;
    cout << temp << endl;
    delete temp;
    temp = NULL;
    cout << temp << endl << endl;
  }
  int i;
  cin >> i;
}