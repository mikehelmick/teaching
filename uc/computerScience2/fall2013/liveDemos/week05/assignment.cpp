#include <iostream>
using namespace std;

class Fraction {
public:
  Fraction(int numerator, int denominator) {
    cout << "normal constructor called" << endl;
    this->numerator = new int;
    *this->numerator = numerator;
    this->denominator = new int;
    *this->denominator = denominator;
  }

  Fraction(const Fraction &other) {
    cout << "copy constructor called" << endl;
    commonInit(other);
  }

  virtual ~Fraction() {
    cout << "destructor called" << endl;
    cout << " deleting " << numerator << " and " << denominator << endl;
    delete numerator;
    delete denominator;
  }

  Fraction& operator=(const Fraction& rhs) {
    cout << "assignment operator called" << endl;
    if (this != &rhs) {
      if (numerator != NULL) {
	      delete numerator;
	      delete denominator;
      }
      commonInit(rhs);
    }
    return *this;
  }

  void inspect() {
    cout << " &this=" << this << endl
        << " \\-> &numerator=" << &numerator << " numerator=" 
        << numerator << " *numerator=" << *numerator << endl
        << " \\-> &denominator=" << &denominator << " denominator="
        << denominator << " *denominator=" << *denominator << endl;
  }
  
private:
  // No reason to make these pointers, other than for this example
  int* numerator;
  int* denominator;

  void commonInit(const Fraction &rhs) {
    this->numerator = new int;
    *this->numerator = *rhs.numerator;
    this->denominator = new int;
    *this->denominator = *rhs.denominator;
  }
};

int main() {
  Fraction a(3, 4);
  a.inspect();
  Fraction b(a);
  b.inspect();
  b = a;
  b.inspect();
}
