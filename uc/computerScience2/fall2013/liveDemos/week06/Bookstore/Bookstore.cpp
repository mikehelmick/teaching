//============================================================================
// Name        : Bookstore.cpp
// Author      : Mike Helmick
// Version     :
// Copyright   : 
// Description : Hello World in C, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <string>

#include <Author.h>
#include <Book.h>

using namespace std;

void printBookDetails(const Book* book) {
	cout << "Book Info: " << endl
	    << " *  Title: " << book->getTitle() << endl
	    << " * Author: " << book->getAuthor()->getName() << endl
        << " *    Web: " << book->getAuthor()->getWebsite() << endl;
}

int main(void) {
  Author* seuss = new Author("Dr. Seus", "http://thelorax.com");
  Author* shakespeare = new Author("William Shakespeare");

  Book* greenEggs = new Book("Green Eggs and Ham", seuss);
  Book* theGrinch = new Book("How the Grinch Stole Christmas", seuss);
  Book* romeo = new Book("Romeo And Julliet", shakespeare);

  printBookDetails(greenEggs);
  printBookDetails(theGrinch);
  printBookDetails(romeo);

  // cleanup books
  // cleanup authors
}
