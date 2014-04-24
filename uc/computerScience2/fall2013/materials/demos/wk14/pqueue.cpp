#include <iostream>
#include <queue>
#include <stdexcept>

using namespace std;


int main(int argc, char* argv[]){
	
	
	priority_queue<string> q;

	/*q.push("Billy");
	q.push("Alice");
	q.push("Bob");
	q.push("Greg");
	q.push("Drew"); */
	
	q.push("5 Billy");
	q.push("8 Alice");
	q.push("12 Bob");
	q.push("10 Greg");
	q.push("1 Drew");
		
	cout << "size: " << q.size() << endl;
	
	while(q.size() > 0){
		cout << q.top() << endl;
		q.pop();
	}
	
	cout << "size: " << q.size() << endl;
	
	return 0;
}