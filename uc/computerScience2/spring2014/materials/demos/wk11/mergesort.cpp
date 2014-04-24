#include <iostream>

using namespace std;

void print(int* array, int length){
	cout << "[";
	for(unsigned int i = 0; i < length; i++){
		cout << array[i] << ", ";
	}
	cout << "]\n";
}

int* sort(int* array, int length){
	if(length <=1 ){
		return array;
	}
	//print(array,length);
		
	int mid = length / 2;
	int* left = new int[mid];
	int* right = new int[length-mid];
	// copy left
	for(unsigned int i = 0; i < mid; i++){
		left[i] = array[i];
	}
	// copy right
	for(unsigned int i = 0; i < length - mid; i++){
			right[i] = array[i+mid];
	}
	// sort both sides
	//print(right,mid);
	//print(left,length - mid);
	//return NULL;
	left = sort(left, mid);
	right = sort(right,length-mid);
	
	// merge!
	int l = 0;
	int r = 0;
	for(int i = 0; i < length; i++){
		//cout << "comparing " << left[l] << " " << right[r] << endl;
		if(r >= length-mid){
			array[i] = left[l];
			l++;
		}else if(l >= mid){
			array[i] = right[r];
			r++;
		}else if(left[l] < right[r]){
			array[i] = left[l];
			l++;
		}else{
			array[i] = right[r];
			r++;
		}
	}
	delete left;
	delete right;
	//print(array,length);
	return array;
}



int main(){
	const int len = 10;
	int* test = new int[len];
	for(unsigned int i = 0; i < len; i++){
		test[i] = rand() % 10;
	}
	print(test, len);
	
	sort(test, len);
	
	print(test, len);
	
}