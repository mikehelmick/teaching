#include <iostream>
#include <vector>
using namespace std;

class Song {
public:
  Song(const string &title, int length) {
    this->title = new string(title);
    this->length = length;
  }

  virtual ~Song() {
    cout << "Destructor called" << endl;
    delete this->title;
  }

  const string* getTitle() {
    return title;
  }

  const int getLength() {
    return length;
  }

private:
  string* title;
  int length;
};

int main() {
  //for (int i = 0; i < 1000000; i++) {
  Song* song = new Song("Thrift Shop", 60*4+33);

  vector<Song*> myVector; // = new vector<Song*>();
  myVector.push_back(song);

  for (int i = 0; i < myVector.size(); i++) {
    delete myVector[i];
    myVector[i] = NULL;
  }

  //delete myVector;
  //}
  //delete song;
  //song = NULL:
}









