#include <iostream>
#include <stdexcept>
#include <vector>
#include <stack>

using namespace std;

template<class T> class MyStack{
public:
	/*MyStack():mysize(0){
		//mysize = 0;  // Paul likes to do this
	}*/
	MyStack(int size):mysize(0),maxsize(size){
		mr = new T[size];
	}
	~MyStack(){}
	void push(T value){
		if(mysize >= maxsize){
			throw length_error("Stack can't be that large!");
		}else{
			mr[mysize] = value;
			mysize++;
		}
	}
	void pop(){
		mysize--;
	}
	T top(){
		if(mysize <= 0){
			throw length_error("Stack is empty");
		}
		return mr[mysize-1];
	}
	int size(){
		return mysize;
	}
private:
	T* mr;
	int mysize;
	int maxsize;
};

int main(int argc, char* argv[]){
	if(argc != 2){
		cout << "I need a number!";
		return 1;
	}
	int size = atoi(argv[1]);
	srand(time(0));
	
	MyStack<int> s(size);
	
	//stack<int> s;
	int sum = 0;
	for(int i = 0; i < size; i++){
		int number = rand() %10;
		sum += number;
		//cout << number << " ";
		s.push(number);
	}
	cout << "sum: " << sum << endl;
	int sum2 = 0;
	for(int i = 0; i < size; i++){
		//cout << s.top() << " ";
		sum2 += s.top();
		s.pop();
	}
	cout << "sum2: " << sum2 << endl;
	return 0;
}