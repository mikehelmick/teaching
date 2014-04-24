#include <iostream>

using namespace std;

int main() {
  bool cond1 = false;
  bool cond2 = false;

  if(cond1) {
    cout << "cond1 " << cond1 << " cond2 " << cond2 << endl;
  } else {
    if(cond2) {
      cout << "cond1 " << cond1 << " cond2 " << cond2 << endl;
    } else {
      cout << "cond1 " << cond1 << " cond2 " << cond2 << endl;
    }
  }

}
