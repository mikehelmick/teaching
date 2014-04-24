/*
 * Author.h
 *
 *  Created on: Oct 3, 2013
 *      Author: helmicmt
 */

#ifndef AUTHOR_H_
#define AUTHOR_H_

#include <string>

using namespace std;

class Author {
public:
	Author(const string &name);
	Author(const string &name, const string &website);
	virtual ~Author();

	const string& getName() const;
	void setName(const string& name);
	const string& getWebsite() const;
	void setWebsite(const string& website);

private:
	string name;
	string website;
};

#endif /* AUTHOR_H_ */
