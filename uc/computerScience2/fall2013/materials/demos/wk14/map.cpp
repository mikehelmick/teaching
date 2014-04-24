#include <iostream>
#include <map>
#include <stdexcept>

using namespace std;


int main(int argc, char* argv[]){

	map<string, int> m;
	
	m["bob"] = 56;
	m["alice"] = 89;
	m["billy"] = 3;
	
	// print it out
	map<string,int>::iterator i;
	for(i = m.begin(); i != m.end(); i++){
		cout << i->first << ": " << i->second << endl;
	}
	
	cout << "size: " << m.size() << endl << endl;
	
	i = m.find("billy");
	if(i == m.end()){ 
		cout << "No billy!\n";
	}else{
		cout << i->first << ": " << i->second << endl;
	}
	
	
	return 0;
}