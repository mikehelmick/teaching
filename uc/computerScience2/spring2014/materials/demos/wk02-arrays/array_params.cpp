#include <iostream>
using namespace std;

void double_entries(int arr[], int arr_size) {
	for (int i = 0; i < arr_size; i++) {
		arr[i] = arr[i] * 2;
	}
}

void print_array(int arr[], int arr_size) {
	cout << " -- printing array -- " << endl;
	for (int i = 0; i < arr_size; i++) {
		cout << " arr[" << i << "] = " << arr[i] << endl;
	}
}

void add_entry(int arr[], int& cur_size, const int capacity) {
	if (cur_size >= capacity) {
		cerr << "ERROR - can't add any more entries";
		return;
	}

  if (cur_size == 0) {
		arr[0] = 1;
		cur_size++;
		return;
  }

	arr[cur_size] = arr[cur_size - 1] + 2;
	cur_size++;
}

int main() {
	int size = 5;
	const int capacity = 10;
	int my_array[capacity] = {1, 3, 5, 7, 9, 0, 0, 0, 0, 0};

	print_array(my_array, size);
	
	cout << "adding elem";
	add_entry(my_array, size, capacity);
	print_array(my_array, size);
	
	cout << "doubling" << endl;
	double_entries(my_array, size);
	print_array(my_array, size);
}