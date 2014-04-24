#include <iostream>
using namespace std;

int main(int argc, const char* argv[]) {
	cout << "# of parameters " << argc << endl;

  // print out the command line parameters
	for (int i = 0; i < argc; i++) {
		cout << "param " << i << " : " << argv[i] << endl;
	}

	cout << "----- my array -----" << endl;
	int my_array[5] = {2, 4, 6, 8, 10};
	int my_array_size = 5;
	int x = 0;
	for (int i = 0; i < my_array_size; i++) {
		cout << "my_array[" << i << "] = " << my_array[i] << endl;
		x++;
	}

	int array2[x];
	for (int i = 0; i <= x * 7; i++) {
		//array2[i] = i;
		cout << "array2[" << i << "] = " << array2[i] << endl;
	}

	return 0;	
}