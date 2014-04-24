/*
 * List.cpp
 * Name: <FILL IN YOUR NAME HERE>
 *
 * November 12, 2013
 */

#include <iostream>

#include "List.h"

using namespace std;

List::List(){
	head = NULL;
	tail = NULL;
	length = 0;
}

List::List(const List& other){
	head = NULL;
	tail = NULL;
	length = 0;
	if(other.length == 0){
		return;
	}
	node_t* othercur = other.head->next;
	node_t* cur = newNode(other.head->value, NULL);
	length++;
	head = cur;
	while(othercur != NULL){
		cur->next = newNode(othercur->value, NULL);
		othercur = othercur->next;
		cur = cur->next;
		length++;
	}
	tail = cur;
}

List::List(int length, int value){
	head = NULL;
	tail = NULL;
	this->length = 0;
	for(int i = 0; i < length; i++){
		pushFront(value);
	}
}

List::~List(){
	node_t* cur = head;
	while(cur != NULL){
		node_t* temp = cur;
		cur = cur->next;
		delete temp;
	}
	head = NULL;
	tail = NULL;
	length = 0;
}

// Getters
int List::size(){
	return length;
}

int List::getFirst(){
	if(head == NULL){
		return 0;
	}
	return head->value;
}

int List::getLast(){
	if(tail == NULL){
		return 0;
	}
	return tail->value;
}

int List::at(int n){
	if(n >= length || -n >= length){	// out of bounds
		return 0;
	}else if(n < 0){
		n = length + n;
	}
	node_t* cur = head;
	while(n > 0 && cur != NULL){
		n--;
		cur = cur->next;
	}
	if(cur == NULL){
		cout << "ERROR!\n";
		return 0;
	}
	return cur->value;
}

bool List::contains(int value){
	node_t* cur = head;
	while(cur != NULL){
		if(cur->value == value){
			return true;
		}
		cur = cur->next;
	}
	return false;
}

bool List::equals(const List& other){
	if(length != other.length){
		return false;
	}
	node_t* cur = head;
	node_t* othercur = other.head;
	while(cur != NULL && othercur != NULL){
		if(cur->value != othercur->value){
			return false;
		}
		cur = cur->next;
		othercur = othercur->next;
	}
	return true;
}

bool List::containsAll(const List& other){
	node_t* cur = other.head;
	while(cur != NULL){
		if(!contains(cur->value)){
			return false;
		}
		cur = cur->next;
	}
	return true;
}

// Setters
void List::pushEnd(int value){
	if(head == NULL && tail == NULL){
		head = newNode(value, NULL);
		tail = head;
		length = 1;
		return;
	}
	//assert(tail == NULL);
	tail->next = newNode(value, NULL);
	tail = tail->next;
	length++;
}

void List::pushFront(int value){
	if(head == NULL && tail == NULL){
		head = newNode(value, NULL);
		tail = head;
		length = 1;
		return;
	}
	//assert(tail == NULL);
	node_t*temp = newNode(value, NULL);
	temp->next = head;
	head = temp;
	length++;
}
int List::popEnd(){
	if(tail == NULL){
		return 0;
	} 
	int ret = tail->value;
	// Get second to last
	node_t* nlast = head;
	if(nlast->next == NULL){// Only 1 element in list
		delete head;
		head = NULL;
		tail = NULL;
		length = 0;
		return ret;
	}
	while(nlast->next->next != NULL){
		nlast = nlast->next;
	}
	delete nlast->next;
	tail = nlast;
	nlast->next = NULL;
	length--;
	return ret;
}

int List::popFront(){
	if(head == NULL){
		return 0;
	}
	int ret = head->value;
	node_t* next = head->next;
	if(next == NULL){// Only 1 element in list
		delete head;
		head = NULL;
		tail = NULL;
		length = 0;
		return ret;
	}
	delete head;
	head = next;
	length--;
	return ret;
}

bool List::setNth(int n, int value){
	if(n > 0 && n >= length){
		return false;
	}
	if(n < -1 * length){
		return false;
	}
	if(n < 0){
		n = length + n;
	}
	node_t* cur = head;
	while(n > 0){
		cur = cur->next;
		n--;
		if(cur == NULL){
			return false;
		}
	}
	// Now cur should be the nth value
	cur->value = value;
	return true;
}

bool List::insertNth(int n, int value){
	if(n >= 0 && n >= length){
		return false;
	}
	if(n < -1 * length){
		return false;
	}
	if(n < 0){
		n = length + n;
	}
	if(n == 0){ // handle the weird case of 0
		pushFront(value);
		return true;
	}
	node_t* cur = head;
	n--; // Stop one early
	while(n > 0){
		cur = cur->next;
		n--;
		if(cur == NULL){
			return false;
		}
	}
	// Now cur should be the n-1th value
	cur->next = newNode(value,cur->next);
	length++;
	return true;
}

int List::deleteNth(int n){
	if(n >= 0 && n >= length){
		return false;
	}
	if(n < -1 * length){
		return false;
	}
	if(n < 0){
		n = length + n;
	}
	if(n == 0){ // handle the weird case of 0
		popFront();
		return true;
	}
	if(n == length-1){
		popEnd();
		return true;
	}
	node_t* cur = head;
	n--; // Stop one early
	while(n > 0){
		cur = cur->next;
		n--;
		if(cur == NULL){
			return false;
		}
	}
	// Now cur should be the n-1th value
	node_t* temp = cur->next;
	cur->next = cur->next->next;
	delete temp;
	length--;
	return true;
}

void List::append(const List& other){
	node_t* temp = other.head;
	while(temp != NULL){
		pushEnd(temp->value);
		temp = temp->next;
	}
}

List List::mesh(const List& other){
	List ret;
	node_t* cur = head;
	node_t* ocur = other.head;
	int alt = 0;
	while(cur != NULL || ocur != NULL){
		if((alt % 2 == 0 || ocur == NULL) && cur != NULL){
			ret.pushEnd(cur->value);
			cur = cur->next;
		}else if(ocur != NULL){
			ret.pushEnd(ocur->value);
			ocur = ocur->next;
		}else{
			cout << "ERROR";
			cout.flush();
		}
		alt++;
	}
	return ret;
}


void List::printList(){
	cout << "[";
	node_t* curr = head;
	if(curr == NULL){
		cout << "]\n";
		return;
	}
	while(curr->next != NULL){
		cout << curr->value << ", ";
		curr = curr->next;
	}
	cout << curr->value << "]\n";
}

node_t* List::newNode(int value, node_t* next){
	node_t* ret = new node_t;
	ret->value = value;
	ret->next = next;
	return ret;
}
