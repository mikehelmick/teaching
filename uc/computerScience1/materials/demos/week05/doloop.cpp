// week05/doloop.cpp
#include <iostream>
using namespace std;

int main() {
  
  int selection = 0;
  do {
    cout << "Do you want number 1, 2, 3, or 4? ";
    cin >> selection;
  } while (selection < 1 || selection > 4);
  
  cout << "You selected " << selection << "." << endl;
  cout << "You have chosen poorly" << endl;
}
