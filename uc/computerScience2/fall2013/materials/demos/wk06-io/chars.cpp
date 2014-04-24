#include <iostream>
#include <fstream>

using namespace std;

int main(){
	ifstream data;
	data.open("data1.txt");   // Needs a C string!
                            
  int i = 1;
	char ch;
	int number;
	while(data.get(ch)){
	  // did we see an integer?
	  if(ch >= '0' && ch <= '9'){
	    data.unget();     // put that character back!
	    data >> number;   // read it as a number
	    cout << i << ": " << number << endl;
	    i++;
	  }
  }
  data.close();
}

