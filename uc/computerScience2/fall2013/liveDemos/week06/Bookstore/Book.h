/*
 * Book.h
 *
 *  Created on: Oct 3, 2013
 *      Author: helmicmt
 */

#ifndef BOOK_H_
#define BOOK_H_

#include <Author.h>

class Book {
public:
	/**
	 * Creates a new book with a shared pointer to an author. The book does not
	 * own the memory associated with the author
	 */
	Book(const string& title, const Author *author);
	virtual ~Book();

	const string getTitle() const;
	const Author* getAuthor() const;

private:
	string title;
	const Author* author;
};


#endif /* BOOK_H_ */
