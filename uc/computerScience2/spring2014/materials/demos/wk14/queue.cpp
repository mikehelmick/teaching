#include <iostream>
#include <queue>
#include <stdexcept>

using namespace std;

template<class T> class MyQueue{
public:
	MyQueue(int size){
		list = new T[size];
		cur = 0;
		mysize = size;
	}

	void push(T value){
		if(cur >= mysize){
			throw length_error("Length error");
		}
		list[cur] = value;
		cur++;
	}
	
	T front(){
		return list[0];
	}
	
	T back(){
		return list[cur-1];
	}
	
	void pop(){
		// SLOW way
		for(int i = 1; i < cur;i++){
			list[i-1] = list[i];
		}
		cur--;
	}
	
	int size(){return cur;}
private:
	T* list;
	int cur;
	int mysize;
};

int main(int argc, char* argv[]){
	if(argc != 2){
		cout << "Enter loop size!\n\n";
		return 1;
	}
	srand(time(0));
	
	//queue<int> s;
	MyQueue<int> s(atoi(argv[1]));
	
	unsigned long sum = 0;
	
	for(int i = 0; i < atoi(argv[1]); i++){
		int number = rand() % 100;
		cout << number << " ";
		sum += number;
		s.push(number);
	}
	cout << "size: " << s.size() << " sum: " << sum << endl;
	
	unsigned long sum2 = 0;
	
	for(int i = 0; i < atoi(argv[1]); i++){
		sum2 += s.front();
		cout << s.front() << " ";
		s.pop();
	}
	
	cout << "size: " << s.size() << " sum2: " << sum2 << endl;
	
	return 0;
}