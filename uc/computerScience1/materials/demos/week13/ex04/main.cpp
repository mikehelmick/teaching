#include <iostream>
using namespace std;

#include <Song.h>

Song* readSong() {
  cout << "Artist? ";
  string artist;
  getline(cin, artist);
  cout << "Title? ";
  string title;
  getline(cin, title);

  Song* song = new Song(artist, title);
  return song;
}

int main() {

  Song* songA = readSong();
  cout << songA->toString() << endl;

  // Pointer assignment. Doesn't create a second copy.
  Song* songB = songA;
  cout << songB->toString() << endl;

  cout << "a: " << songA << " b: " << songB << endl;

  delete songA;
  songA = NULL;

  

}
