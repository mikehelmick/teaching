/*
 * Sort.cpp
 * Name: Paul Talaga
 *
 * November 5, 2013
 *
 * All but yourBestSort are NOT optimized for speed.  They work, but aren't fast.
 * See yourBestSort for tricks on optimizations.
 *
 * The comments in these functions are very sparse!  More are needed.
 */

#include <iostream>
#include <vector>
//#include <limits>  // An attemp to not hardcode in the max char value.  Is not portable.
#include <string.h> 
#include "Sort.h"

using namespace std;

/*
 * Selection sort
 */
vector<int> Sort::selectionSort(const vector<int>& array){
	if(array.size() <= 1 || isSorted(array)){
		return array;
	}
	vector<int> ret(array);
	for(unsigned int i = 0; i < ret.size()-1; i++){
		int mini = i;
		for(unsigned int j = i+1; j < ret.size();j++){
			if(ret[j] < ret[mini]){	// swap
				mini = j;
			}
		}
		// now swap
		int temp = ret[i];
		ret[i] = ret[mini];
		ret[mini] = temp;
	}
	return ret;
}

/*
 * Cocktail sort
 */
vector<int> Sort::cocktailSort(const vector<int>& array){
	if(array.size() <= 1 || isSorted(array)){
		return array;
	}
	vector<int> ret(array);
	int low = 0;
	int high = ret.size() - 1;
	int t = 0;
	while(low <= high){
		//printArray(ret);
		// Go up
		for(int i = low; i < high; i++){
			if(ret[i] > ret[i+1]){
				t = ret[i];
				ret[i] = ret[i+1];
				ret[i+1] = t;
			}
		}
		high--;
		// Go down
		for(int i = high; i >= low; i--){
			if(ret[i] > ret[i+1]){
				t = ret[i];
				ret[i] = ret[i+1];
				ret[i+1] = t;
			}
		}
		low++;
	}
	return ret;
}

/*
 * Gnome sort
 */
vector<int> Sort::gnomeSort(const vector<int>& array){
	if(array.size() <= 1|| isSorted(array)){
		return array;
	}
	vector<int> ret(array);
	int j = 0;
	int t = 0;
	for(unsigned int i = 0; i < ret.size()-1; i++){
		if(ret[i] > ret[i+1]){
			// switch until it doesn't make sense to
			j = i;
			while(ret[j] > ret[j+1] && j >= 0){
				t = ret[j];
				ret[j] = ret[j+1];
				ret[j+1] = t;
				j--;
			}
		}
	}
	return ret;
}

/*
 * Shell Sort using selection sort inside
 */
vector<int> Sort::shellSort(const vector<int>& array){
	if(array.size() <= 1 || isSorted(array)){
		return array;
	}
	
	unsigned int start_jump = array.size()/2;
	vector<int> ret(array);

	int jump = start_jump;
	while(jump > 0){
		for(unsigned int offset = 0; offset < jump; offset++){
			// now do selection sort
			for(unsigned int i = offset; i < ret.size(); i = i + jump){	// note the strange increment
				// find min
				int mini = i;
				for(unsigned int k = i+jump; k < ret.size(); k = k + jump){
					if(ret[mini] > ret[k]){
						mini = k;
					}
				}
				// now swap
				int temp = ret[mini];
				ret[mini] = ret[i];
				ret[i] = temp;
			}
		}
		jump = jump / 2;
	}
	return ret;
}

/* yourBestSort
 * This is a variant on the idea behind radix sort taken to an extreme.
 * We make a series of buckets, one per possible number in the array to sort.
 * These buckets start at 0, until that number is seen, and then incremented by 1.
 * Thus at the end I can go through my list of buckets and just print out numbers based on 
 * the bucket index and the value in the bucket.
 * Runtime is O(n), times a constant related to the max and min values of the array.
 * Note that this is HEAVILY dependent on the values in the list.  For example to
 * sort an array with 2 elements [0, <MAX_INT>] will require 4GB of ram!
 */
vector<int> Sort::yourBestSort(const vector<int>& arr){
	if(arr.size() <= 1 || isSorted(arr)){	// Bail if a short list or already sorted.
		return arr;
	}
	unsigned int arrsize = arr.size();	// It is faster to store the size rather than
																			// calling a function every time.
	const int* array = &(arr[0]);	// Array indexing is faster than vector (surprisingly), so
	// get a pointer to the internal array in the vector.
	// This is done by asking for the address of the fist element.
	
	// Find max and min values so we know how many buckets we need.
	int max = array[0];
	int min = array[0];
	for(unsigned int i = 0; i < arrsize; i++){
		if(max < array[i]){
			max = array[i];
		}else if(min > array[i]){
			min = array[i];
		}
	}
	
	unsigned int cntsize = max-min+1;	// How many buckets are required.
	// Now make an array of length cntsize
	// For space efficiency we store the number of times we've seen a number in an
	// unsigned char, which is one byte, which has a maximum value of 255.  Thus if
	// There are more than 255 numbers with the same value in array we're in trouble!
	// Note that this is SLOWER than having an array of ints because the processor needs
	// to do bit shifts to get access to 1-byte segments.  
	unsigned char* cnt = new unsigned char[cntsize];
	// Fill with 0s
	memset(cnt, 0, cntsize * sizeof(char));	// This fills the entire array with 0's very
																					// fast.  A for loop would have been equivalent.
	
	// Now go through our unsorted list and increment the number at that index
	for(unsigned int i = 0; i < arrsize; i++){
		if(cnt[array[i] - min] == 255 ){ //UCHAR_MAX){	// defined in limits.h
			cout << "Can not sort this list due to internal limitations!\n";
			vector<int> ret;
			return ret;					// Bail!
		}
		cnt[array[i] - min]++;
	}
	vector<int> ret(arrsize);	// This initializes ret with 0s, with the correct length.
	int* retar = &(ret[0]);	// We MUST be sure the vector is long enough before index in.
	// Now go through cnt and add those numbers to ret
	int reti = 0;		// Keep track of our current index in ret (retar)
	for(unsigned int i = 0; i < cntsize; i++){
		int numberof = cnt[i];
		for(int j = 0; j < numberof; j++){	// If we saw more than one value, put that number
			retar[reti] = i+min;							// of values into the ret.
			reti++;
		}
	}
	delete cnt;	// Give my memory back!
	
	return ret;
}

bool Sort::isSorted(const vector<int>& array){
	if(array.size() <= 1){
		return true;
	}
	int cur = array[0];
	for(unsigned int i = 1; i < array.size(); i++){
		if(cur > array[i]){	// Do pairwise comparisons and if we find a violation, bail with false.
			return false;
		}
		cur = array[i];
	}
	return true;
}


void Sort::printArray(const vector<int>& array){
	cout << "[";
	for(unsigned int i = 0; i < array.size(); i++){
		cout << array[i] << ", ";
	}
	cout << "]\n";
}