#include <iostream>
using namespace std;

int main() {
  bool result = true;
  bool result2 = false;

  bool result3 = result || result2;
  bool result4 = result && (!result2 || result3);

  cout << "sizeof " << sizeof(result) << endl;

  result = 128;
  cout << "result is " << result << endl;

  return 0;
}
