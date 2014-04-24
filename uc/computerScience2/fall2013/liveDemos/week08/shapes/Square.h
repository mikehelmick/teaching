
#include <Shape.h>

class Square : public Shape {
public:
  Square(int sideLength);
  virtual ~Square();

  virtual double area() const;
  virtual double primater() const;  
private:
  int sideLength;
  Square();
};
