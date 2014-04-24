#include <iostream>
#include <fstream>

using namespace std;

int main(){
	ifstream data;
	data.open("data1.txt");

  int i = 1;
	int number;
	while(data >> number){
	  cout << i << ": " << number << endl;
	  i++;
  }
  data.close();
}

