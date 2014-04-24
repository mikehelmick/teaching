
#include <Rectangle.h>

class Square : public Rectangle {
public:
  Square(int sideLength);
  virtual ~Square();

  virtual bool isEqual(Shape* rhs);

private:

};
