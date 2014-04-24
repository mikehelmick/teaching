#include <cstdlib>

#include "Die.h"

using namespace std;

Die::Die(){
	d1 = -1;
	d2 = -1;
};
	
int Die::roll(){
	d1 = (rand()%6) + 1;
	d2 = (rand()%6) + 1;
	return d1 + d2;
}
	
bool Die::wasDoubles(){
	//return d1 > 2;
	return d1==d2;
};

int Die::getD1() {
  return d1;
}

int Die::getD2() {
  return d2;
}
	