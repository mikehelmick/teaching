#include <iostream>
#include <set>

using namespace std;


int main(int argc, char* argv[]){
	if(argc != 2){
		cout << "I need a number!";
		return 1;
	}
	int size = atoi(argv[1]);
	srand(time(0));
	
	multiset<int> s;
	
	for(int i =0; i < size; i++){
		int number = rand() % 10;
		cout << number << " ";
		s.insert(number);
	}
	cout << "size: " << s.size() << endl;
	
	set<int>::iterator i;
	for(i = s.begin(); i != s.end(); i++){
		cout << *i << " ";
	}
	
	cout << endl;
	for(i = (++s.end()); i != (--s.begin()); i--){
		cout << *i << " ";
	}
	cout << endl;
	
}