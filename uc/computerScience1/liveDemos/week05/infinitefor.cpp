#include <iostream>
using namespace std;

int main() {

   int x = 0;

   for (;;) {
     x++;
     cout << x << " ";

     if (x >= 100000) {
       break;
     }
   }

   cout << "exited loop. " << endl;
}

