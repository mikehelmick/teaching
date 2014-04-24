#include <iostream>
#include <string>
#include <map>

using namespace std;


int main(int argc, char* argv[]){
	
	srand(time(0));
	
	multimap<string,long> s;
	
	s.insert(pair<string, long>("toby",1234517890));
	s.insert(pair<string, long>("toby",1234517891));
	s.insert(pair<string, long>("sam",1234607890));
	
	cout << "size: " << s.size() << endl;
	
	multimap<string,long>::iterator i;
	i = s.find("toby");
	cout << i->first << " " << i->second << endl;
	i++;
	cout << i->first << " " << i->second << endl;
	i++;
	cout << i->first << " " << i->second << endl;
	i++;
	cout << i->first << " " << i->second << endl;
	i++;
	cout << i->first << " " << i->second << endl;
	
	/*for(i = s.begin(); i != s.end(); i++){
		cout << i->first << ": " << i->second << " " << endl;
	}*/
	

	
}