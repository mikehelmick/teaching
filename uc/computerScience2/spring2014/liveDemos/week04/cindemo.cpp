#include <iostream>

using namespace std;

int main() {
 
  cout << "Enter operator and fractions: ";

  char op = ' ';
  cin >> op;

  if (op != 'x') {
    int n1,d1,n2,d2;
    char sep;

    cin >> n1 >> sep >> d1 >> n2 >> sep >> d2;

    cout << n1 << "/" << d1 << " " << op << " " << n2 << "/" << d2 << endl;
  }

  cout << "Done" << endl;
}
