/*
 * List.cpp
 * Name: Paul Talaga
 *
 * November 18, 2013
 */

#include <iostream>

#include "List.h"

using namespace std;

List::List():head(NULL),tail(NULL),length(0){}

List::List(const List& other):head(NULL),tail(NULL),length(0){
	node_t* cur = other.head;   
	while(cur != NULL){
	  pushEnd(cur->value);    // This takes advantage that pushEnd is cheap because we have a tail pointer.
	  cur = cur->next;
	}
}

List::List(int length, int value):head(NULL),tail(NULL),length(0){
	for(int i = 0; i < length; i++){
		pushFront(value);                             // Let pushFront do all the work!
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
	if(n >= length || -n > length){	// out of bounds check
		return 0;
	}else if(n < 0){  // flip if negative
		n = length + n;
	}
	node_t* cur = head;
	while(n > 0 && cur != NULL){  
		n--;
		cur = cur->next;
	}
	if(cur == NULL){
		cout << "ERROR!\n";   // This should never get tripped or else length is wrong.
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
	if(length != other.length){ // Do lengths differ?
		return false;
	}
	node_t* cur = head;
	node_t* othercur = other.head;
	while(cur != NULL && othercur != NULL){ // Step through both in step
		if(cur->value != othercur->value){
			return false;
		}
		cur = cur->next;
		othercur = othercur->next;
	}
	return cur == othercur;   // Make sure one wasn't shorter than the other.
}

bool List::containsAll(const List& other){
	node_t* cur = other.head;
	while(cur != NULL){
		if(!contains(cur->value)){
			return false;
		}
		cur = cur->next;
	}
	return true;  // Must have found them all!
}

// Setters
void List::pushEnd(int value){
	if(head == NULL && tail == NULL){  // Empty list check
		head = newNode(value, NULL);
		tail = head;
		length = 1;
		return;
	}
	tail->next = newNode(value, NULL);
	tail = tail->next;
	length++;
}

void List::pushFront(int value){    // Empty list check
	if(head == NULL && tail == NULL){
		head = newNode(value, NULL);
		tail = head;
		length = 1;
		return;
	}
	head = newNode(value, head);
	length++;
}

int List::popEnd(){
	if(tail == NULL){ // Empty list!
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
	while(nlast->next->next != NULL){ // Zip down list and get second to last
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
	if(n > 0 && n >= length){ // pos check
		return false;
	}
	if(n < -1 * length){      // neg check
		return false;
	}
	if(n < 0){                // make positive
		n = length + n;
	}
	node_t* cur = head;
	while(n > 0){
		cur = cur->next;
		n--;
		if(cur == NULL){  // Bail if we had a length error
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
		return 0;
	}
	if(n < -1 * length){
		return 0;
	}
	if(n < 0){
		n = length + n;
	}
	if(n == 0){ // handle the weird case of 0
		return popFront();
	}
	if(n == length-1){
		return popEnd();
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
	int ret = temp->value;
	cur->next = cur->next->next;
	delete temp;
	length--;
	return ret;
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
	while(cur != NULL || ocur != NULL){     // While there are pointers, push!
		if((alt % 2 == 0 || ocur == NULL) && cur != NULL){  // () important!
			ret.pushEnd(cur->value);
			cur = cur->next;
		}else if(ocur != NULL){
			ret.pushEnd(ocur->value);
			ocur = ocur->next;
		}else{
			cout << "ERROR";  // Just a check, this should never get printed!
			cout.flush();
		}
		alt++;
	}
	return ret;
}


void List::printList(){
	cout << "[";
	node_t* curr = head;
	if(curr == NULL){   // This is neccessary so the last line doesn't segfault.
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
