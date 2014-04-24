#include <iostream>
#include <string>
using namespace std;

class Pixel {
public:
  Pixel(int nr, int ng, int nb) {
    r = normal(nr);
    g = normal(ng);
    b = normal(nb);
  }
  
  int getRed() {
    return r;
  }
  
  int getGreen() {
    return g;
  }
  
  int getBlue() {
    return b;
  }
  
  void brighten(double percent) {
    r = brighten(r, percent);
    g = brighten(g, percent);
    b = brighten(b, percent);
  }
  
  void darken(double percent) {
    r = darken(r, percent);
    g = darken(g, percent);
    b = darken(b, percent);
  }

  string asHex() {
    string s = "0x" + asString(r) + asString(g) + asString(b);
    return s;
  }

private:
  int r;
  int g;
  int b;

  static int darken(double val, double percent) {
    return normal((int) (val - val * percent));
  }
    
  static int brighten(double val, double percent) {
    return normal((int) (val + val * percent));
  }
  
  static string asString(int val) {
    char buffer[2];
    sprintf(buffer, "%02x", val);    
    string s(buffer);
    return s;
  }

  static int normal(int val) {
    if (val < 0) {
      return 0;
    } else if (val > 255) {
      return 255;
    }
    return val;
  }
};

int main() {
  Pixel p(122, 4, 250);
  cout << p.asHex() << endl;
  p.brighten(.5);
  cout << p.asHex() << endl;
  p.darken(0.75);
  cout << p.asHex() << endl;
}