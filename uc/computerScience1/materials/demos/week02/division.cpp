#include <iostream>
using namespace std;

int main() {
  
  int a = 12;
  int b = 44345;
  
  int res = b / a;
  int rem = b % a;
  
  float result = b / (float)a;
  
  cout << "b/a = " << res << " remainder " << rem << endl;
  cout << "b/a = " << result << endl;
  
  return 0;
}

