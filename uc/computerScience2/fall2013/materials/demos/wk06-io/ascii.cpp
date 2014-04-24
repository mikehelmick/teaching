#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int main(){
  const string file = "ascii.txt";

	ofstream data;
	data.open(file.c_str());   // Needs a C string!
                            
  for(int i = 33; i < 127; i++){
    char c = static_cast<char>(i);
    data << i << ": " << c << endl;
  }  
  
  data.close();
}
