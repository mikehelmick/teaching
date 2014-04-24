/*
 * Author.cpp
 *
 *  Created on: Oct 3, 2013
 *      Author: helmicmt
 */

#include "Author.h"

Author::Author(const string &name) : name(name) {
}

Author::Author(const string &name, const string &website) : name(name), website(website) {
}

Author::~Author() {
}

const string& Author::getName() const {
	return name;
}

void Author::setName(const string& name) {
	this->name = name;
}

const string& Author::getWebsite() const {
	return website;
}

void Author::setWebsite(const string& website) {
	this->website = website;
}

