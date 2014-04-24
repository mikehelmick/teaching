// week05/infinitefor.cpp

#include <iostream>
using namespace std;

int main() {
  
  int x = 0;
  
  // This is an infinite for loop, will never termine on it's own
  for(;;) {
    x++;
    cout << x << " ";
    
    if (x >= 100000) {
      break;
    } 
  }
  
  cout << "Exited loop via break" << endl;
}