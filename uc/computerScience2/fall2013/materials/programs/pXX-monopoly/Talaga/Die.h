#ifndef DIE_H
#define DIE_H

using namespace std;

class Die{
public:
	Die();
	
	int roll();
	bool wasDoubles();
  
  int getD1();
  int getD2();
	
private:
	
	int d1;
	int d2;
	
};


#endif