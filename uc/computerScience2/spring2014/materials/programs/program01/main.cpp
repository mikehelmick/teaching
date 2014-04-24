#include <iostream>

#include <Fraction.h>

int main(int argc, char* argv[]) {
  cout << "Enter fraction operations like + 1/2 1/3: ('q' to quit)" << endl;

  while (true) {
    char op;
    cin >> op;
    if (op == 'q') {
      break;
    }
    char trash;
    int num1, den1, num2, den2;
    cin >> num1 >> trash >> den1 >> num2 >> trash >> den2;

    Fraction a(num1, den1);
    Fraction origA(a);
    Fraction b(num2, den2);

    switch (op) {
      case '+':
        a.add(b);
        break;
      case '-':
        a.subtract(b);
        break;
      case '*':
        a.multiply(b);
        break;
      case '/':
        a.divide(b);
        break;
      default:
        cout << "Invalid operation, skipping." << endl;
        continue;
    }
    cout << origA.toString() << " " << op << " " << b.toString() << " = " << a.toString() << endl;
  }
  
  return 0;
}