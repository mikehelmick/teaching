#include <iostream>

using namespace std;

void print(int* array, int length){
	cout << "[";
	for(unsigned int i = 0; i < length; i++){
		cout << array[i] << ", ";
	}
	cout << "]\n";
}

void sort(int* array, int len){
	if(len <= 1){
		return;
	}
	//split array in half
	int middle = len / 2;
	int* left = new int[middle];
	int* right = new int[len-middle];
	for( int i = 0; i < middle; i++){
		left[i] = array[i];
	}
	for( int i = 0; i < len-middle; i++){
		right[i] = array[i+middle];
	}
	//print(left,middle);
	//print(right,len-middle);
	// sort each half - sort using sort
	sort(left, middle);
	sort(right, len-middle);
	
	// merge two halves together
	int l = 0;
	int r = 0;
	for( int i = 0; i < len; i++){
		if(l >= middle){	// Nothing left in left
			array[i] = right[r];
			r++;
		}else if(r >= len-middle){	// Nothing left in right
			array[i] = left[l];
			l++;
		}else if(left[l] < right[r]){ // Left is smaller
			array[i] = left[l];
			l++;
		}else{										// Right is smaller
			array[i] = right[r];
			r++;
		}
	}
	delete left;
	delete right;
	return;
}

bool isSorted(int* array, int length){
	for(int i = 0; i < length-1; i++){
		if(array[i] > array[i+1]){
			return false;
		}
	}
	return true;
}

int main(){
	const int len = 2000000;
	int* test = new int[len];
	for(unsigned int i = 0; i < len; i++){
		test[i] = rand() ;
	}
	//print(test, len);
	
	sort(test, len);
	
	//print(test, len);
	cout << "isSorted: " << isSorted(test,len)<< endl;
	
}