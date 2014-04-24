#include <iostream>
using namespace std;

class Song {
public:
  Song(const string &title, int length) {
    this->title = new string(title);
    this->length = length;
  }

  virtual ~Song() {
    //delete this->title;
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
  Song* song = new Song("Thrift Shop", 60*4+33);
  delete song;
  song = NULL;
  delete song;
}
