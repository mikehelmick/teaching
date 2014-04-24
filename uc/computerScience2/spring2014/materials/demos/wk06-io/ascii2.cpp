#include <string>
#include <iostream>
#include <fstream>

using namespace std;

void printLine(ostream& stream, int value){
  char c = static_cast<char>(value);
  stream << value << ": " << c << endl;
}

int main(){
  const string file = "ascii.txt";

	ofstream data;
	data.open(file.c_str());   // Needs a C string!
  
                            
  for(int i = 33; i < 127; i++){
    printLine(data,i);
  }  
  
  data.close();
}
