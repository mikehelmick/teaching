#include <iostream>
using namespace std;

int main() {
  
  double value = 3.99999;
  
  long longValue = static_cast<long>(value);
  cout << "casted: " << longValue << endl;
  long oldSchool = (long)value;
  cout << "casted: " << oldSchool << endl;
  
}