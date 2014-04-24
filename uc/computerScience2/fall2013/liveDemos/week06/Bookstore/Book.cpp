/*
 * Book.cpp
 *
 *  Created on: Oct 3, 2013
 *      Author: helmicmt
 */

#include <Book.h>

Book::Book(const string& title, const Author* author) : title(title), author(author) {

}

Book::~Book() {
	// TODO Auto-generated destructor stub
}

const string Book::getTitle() const {
	return title;
}

const Author* Book::getAuthor() const {
	return author;
}
