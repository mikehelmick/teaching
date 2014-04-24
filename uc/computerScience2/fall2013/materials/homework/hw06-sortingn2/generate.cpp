#include <iostream>

using namespace std;

main(){
	srand(time(0));
	for(int i = 0; i < 100000; i++){
		cout << rand() % 100 + i << endl;
	}

}