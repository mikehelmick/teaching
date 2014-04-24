#include <iostream>
#include <queue>
#include <stdexcept>

using namespace std;

class Pair {
public:
  Pair(int priority, string value)
      : priority(priority), value(value) {
  }

  string getValue() const {
    return value;
  }

  int getPriority() const {
    return priority;
  }

  bool operator<(const Pair &rhs) const {
    return priority > rhs.priority;
  }

private:
  int priority;
  string value;
};

Pair createPair(int pri, string val) {
  Pair p(pri, val);
  return p;
}

int main(int argc, char* argv[]){
	
	
	priority_queue<Pair> q;
/*
	q.push("Billy");
	q.push("Alice");
	q.push("Bob");
	q.push("Greg");
	q.push("Drew"); 
 */

	q.push(createPair(5, "Billy"));
	q.push(createPair(8, "Alice"));
	q.push(createPair(12, "Bob"));
	q.push(createPair(10, "Greg"));
	q.push(createPair(1, "Drew"));
		
	cout << "size: " << q.size() << endl;
	
	while(q.size() > 0){
          Pair pair = q.top();
	  cout << pair.getValue() << "   (pri: " << pair.getPriority() << ")" << endl;
	  q.pop();
	}
	
	cout << "size: " << q.size() << endl;
	
	return 0;
}










