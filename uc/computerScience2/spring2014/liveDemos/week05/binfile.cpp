#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]) {

  ifstream inFile;
  inFile.open(argv[1]);


  inFile.close();
  return 0;
}
