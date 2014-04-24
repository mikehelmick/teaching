#include <iostream>
#include <set>
//#include <multiset>
#include <stdexcept>

using namespace std;


int main(int argc, char* argv[]){
	if(argc != 2){
		cout << "Enter loop size!\n\n";
		return 1;
	}
	srand(time(0));
	
	//set<int> s;
	multiset<int> s;
	
	unsigned long sum = 0;
	
	const int range = 10;
	
	for(int i = 0; i < atoi(argv[1]); i++){
		int number = rand() % range;
		cout << number << " ";
		sum += number;
		s.insert(number);
	}
	cout << "size: " << s.size()  << endl;
	
	unsigned long sum2 = 0;
	
	/*for(int i = 0; i < range; i++){
		cout << i << ":";
		if(s.count(i) >= 1){
			cout << s.count(i);
		}
		cout << endl;
	} */
	
	set<int>::iterator i;
	for(i = s.begin(); i != s.end(); i++){
		cout << *i << ":";
		if(s.count(*i) >= 1){
			cout << s.count(*i);
		}
		cout << endl;
	}
	
	
	return 0;
}