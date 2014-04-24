/*
 * main.cpp
 * Name: Paul Talaga
 *
 * This program sorts numbers provided in a text file, and prints out the sorted
 * number to stdout (the screen).
 * It accepts 2 command-line parameters, the first an integer representing
 * the sort to use.  0 Selection sort, 1 Coctail sort, 2 Gnomesort, 3 Shellsort, 
 * 4 Your Best Sort.
 * The second paremeter is a filename of a file containing the numbers to sort.
 * The file has one integer (could have many digits) per line.
 *
 * Oct 23 ,2013
 */

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "Sort.h"

using namespace std;

int main(int argc, char* argv[]){
	if(argc != 3){
		cout << "Please enter sort type [0-4] followed";
		cout << " by the text file you'd like to sort\n";
		return 0;
	}
	// Open file
	ifstream file;
	file.open(argv[2]);
	if(file.fail()){
		cout << "Error openeing file.\n";
		return 0;
	}
	
	vector<int> numbers;
	int num;
	while(file >> num){
		numbers.push_back(num);
	}
	file.close();
	
	unsigned int startlength = numbers.size();
	
	int sort = atoi(argv[1]);
	Sort s;
	if(sort == 0){ // Selection sort
		numbers = s.selectionSort(numbers);
	}else if(sort == 1){		// Cocktail sort
		numbers = s.cocktailSort(numbers);
	}else if(sort == 2){		// Gnome sort
		numbers = s.gnomeSort(numbers);
	}else if(sort == 3){		// Shell sort
		numbers = s.shellSort(numbers);
	}else if(sort == 4){		// my best sort
		numbers = s.yourBestSort(numbers);
	}else{
		cout << sort << " not a valid sort.\n";
		return 0;
	}
	// Verify the sort seems correct.
	if(! s.isSorted(numbers)){
		cout << "NOT SORTED!\n";
		return 1;
	}
	if(startlength != numbers.size()){
		cout << "LOST NUMBERS!\n";
		return 1;
	}
	// Would also be good to check to see if the same numbers were in the sorted version
	// as the unsorted version (scoreboard site does this).
	
	// Print the values to stdout
	for(unsigned int i = 0; i < numbers.size(); i++){
		cout << numbers[i] << endl;
	}
	
	return 0;
}