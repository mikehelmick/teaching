#include <iostream>
using namespace std;

int main() {
  
  cout << "How many months (1-12)? ";
  int num;
  cin >> num;
  
  switch (num) {
    case 12: cout << "December" << endl;
    case 11: cout << "November" << endl;
    case 10: cout << "October" << endl;
    case  9: cout << "September" << endl;
    case  8: cout << "August" << endl;
    case  7: cout << "July" << endl;
    case  6: cout << "June" << endl;
    case  5: cout << "May" << endl;
    case  4: cout << "April" << endl;
    case  3: cout << "March" << endl;
    case  2: cout << "February" << endl;
    case  1: cout << "January" << endl;
             break;
    defult:
      cout << "No months available" << endl;
  }  
}