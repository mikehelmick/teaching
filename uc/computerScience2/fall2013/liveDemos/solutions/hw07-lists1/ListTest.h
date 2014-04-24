#ifndef LIST_TEST_H
#define LIST_TEST_H

/*
 * ListTest.h
 * Name: Paul Talaga
 *
 * November 30, 2013
 */

#include "List.h"
#include <cstdlib>

#include <cxxtest/TestSuite.h>

using namespace std;

class ListTest : public CxxTest::TestSuite{
public:

	// Constructors
  void testConValue1() {
    List l(0,5);
		TS_ASSERT(l.size() == 0);
  }
	
  void testConValue2() {
    List l(4,5);
		TS_ASSERT(l.size() == 4);
		TS_ASSERT(l.at(0) == 5);
  }
  
  void testConValue3() {
    List l(5,6);
		TS_ASSERT(l.size() == 5);
		TS_ASSERT(l.at(4) == 6);
  }
	
  void testConSizeEnd0() {
    List l;
		TS_ASSERT(l.size() == 0);
  }
  
  // Copy Constructor
  void testConCopy1() {
    List l;
		l.pushEnd(5);
		List m(l);
		TS_ASSERT(l.size() == 1);
		TS_ASSERT(m.size() == 1);
  }
  
  void testConCopy2() {
    List l;
		l.pushEnd(5);
		List m(l);
		l.pushEnd(6);
		TS_ASSERT(l.size() == 2);
		TS_ASSERT(m.size() == 1);
  }
  
  void testConCopy3() {
    List l;
		l.pushEnd(5);
		List m(l);
		m.pushEnd(6);
		m.pushEnd(7);
		TS_ASSERT(l.size() == 1);
		TS_ASSERT(m.size() == 3);
  }
	
  void testConSizeEnd1() {
    List l;
		l.pushEnd(5);
		TS_ASSERT(l.size() == 1);
  }
	
  void testConSizeEnd2() {
    List l;
		l.pushEnd(6);
		l.pushEnd(7);
		TS_ASSERT(l.size() == 2);
  }
  
  void testConSizeEnd3() {
    List l;
		l.pushEnd(8);
		l.pushEnd(9);
		l.pushEnd(10);
		TS_ASSERT(l.size() == 3);
  }
  
  void testPushEnd1() {
    List l;
		l.pushEnd(8);
		l.pushEnd(9);
		l.pushEnd(10);
		TS_ASSERT(l.size() == 3);
		TS_ASSERT(l.at(2) == 10);
		TS_ASSERT(l.at(0) == 8);
  }
  
  void testPushEnd2() {
    List l;
		l.pushEnd(8);
		TS_ASSERT(l.size() == 1);
		TS_ASSERT(l.at(0) == 8);
  }
	
	
  void testConSizeFront1() {
    List l;
		l.pushFront(5);
		TS_ASSERT(l.size() == 1);
  }
	
  void testConSizeFront2() {
    List l;
		l.pushFront(7);
		l.pushFront(6);
		TS_ASSERT(l.size() == 2);
  }
  
  void testConSizeFront3() {
    List l;
		l.pushFront(10);
		l.pushFront(9);
		l.pushFront(8);
		TS_ASSERT(l.size() ==3);
  }
  
    void testSizeFront1() {
    List l;
		l.pushFront(5);
		TS_ASSERT(l.size() == 1);
  }
	
  void testSizeFront2() {
    List l;
		l.pushFront(7);
		l.pushFront(6);
		TS_ASSERT(l.size() == 2);
  }
  
  void testSizeFront3() {
    List l;
		l.pushFront(10);
		l.pushFront(9);
		l.pushFront(8);
		TS_ASSERT(l.size() ==3);
  }
  
  void testSizeFront4() {
    List l;
		TS_ASSERT(l.size() ==0);
  }
	
  void testPushFrontAt() {
    List l;
		l.pushFront(1);
		TS_ASSERT(l.at(0) == 1);
		l.pushFront(5);
		TS_ASSERT(l.at(0) == 5);
  }
	
  void testAtBad() {
    List l;
		l.pushFront(4);
		l.pushFront(3);
		l.pushFront(2);
		l.pushFront(1);
		TS_ASSERT(l.at(4) == 0);
  }
	
  void testAtNeg() {
    List l;
		l.pushFront(4);
		l.pushFront(3);
		l.pushFront(2);
		l.pushFront(1);
		TS_ASSERT(l.at(-1) == 4);
		TS_ASSERT(l.at(-2) == 3);
		TS_ASSERT(l.at(-3) == 2);
		TS_ASSERT(l.at(-4) == 1);
		TS_ASSERT(l.at(-5) == 0);
  }
	
  void testAt() {
    List l;
		l.pushFront(4);
		l.pushFront(3);
		l.pushFront(2);
		l.pushFront(1);
		TS_ASSERT(l.at(0) == 1);
		TS_ASSERT(l.at(1) == 2);
		TS_ASSERT(l.at(2) == 3);
		TS_ASSERT(l.at(3) == 4);
		TS_ASSERT(l.at(4) == 0);
  }
	
  void testFirstEmpty() {
    List l;
		TS_ASSERT(l.getFirst() == 0);
  }
	
  void testLastEmpty() {
    List l;
		TS_ASSERT(l.getLast() == 0);
  }
	
  void testFirst() {
    List l;
		l.pushFront(4);
		TS_ASSERT(l.getFirst() == 4);
		l.pushFront(3);
		l.pushFront(2);
		l.pushFront(1);
		TS_ASSERT(l.getFirst() == 1);
  }
	
  void testLast() {
    List l;
		l.pushFront(4);
		l.pushFront(3);
		l.pushFront(2);
		l.pushFront(1);
		TS_ASSERT(l.getLast() == 4);
  }
	
  void testContainsEmpty() {
    List l;
		TS_ASSERT(l.contains(4) == false);
  }
	
  void testContainsFirst() {
    List l;
		l.pushFront(4);
		l.pushFront(3);
		l.pushFront(2);
		l.pushFront(1);
		TS_ASSERT(l.contains(1) == true);
  }
	
  void testContainsLast() {
    List l;
		l.pushFront(4);
		l.pushFront(3);
		l.pushFront(2);
		l.pushFront(1);
		TS_ASSERT(l.contains(4) == true);
  }
	
  void testContainsMiddle() {
    List l;
		l.pushFront(4);
		l.pushFront(3);
		l.pushFront(2);
		l.pushFront(1);
		TS_ASSERT(l.contains(3) == true);
  }
	
  void testContainsNone() {
    List l;
		l.pushFront(4);
		l.pushFront(3);
		l.pushFront(2);
		l.pushFront(1);
		TS_ASSERT(l.contains(5) == false);
  }
	
  void testEqualsMatch() {
    List l;
		l.pushFront(3);
		l.pushFront(2);
		l.pushFront(1);
    List r;
		r.pushFront(3);
		r.pushFront(2);
		r.pushFront(1);
		TS_ASSERT(l.equals(r) == true);
  }
	
  void testEqualsMatchEmpty() {
    List l;
    List r;
		TS_ASSERT(l.equals(r) == true);
  }
	
  void testEqualsNoMatch1() {
    List l;
		l.pushFront(3);
    List r;
		TS_ASSERT(l.equals(r) == false);
  }
	
  void testEqualsNoMatch2() {
    List l;
    List r;
		r.pushFront(3);
		TS_ASSERT(l.equals(r) == false);
  }
	
  void testContainsAllTrue() {
    List l;
		l.pushFront(3);
		l.pushFront(2);
		l.pushFront(1);
    List r;
		r.pushFront(3);
		r.pushFront(2);
		r.pushFront(1);
		TS_ASSERT(l.containsAll(r) == true);
  }
	
  void testContainsAllEmpty() {
    List l;
    List r;
		TS_ASSERT(l.containsAll(r) == true);
  }
	
  void testContainsAll1() {
    List l;
		l.pushFront(3);
    List r;
		TS_ASSERT(l.containsAll(r) == true);
  }
	
  void testContainsAll2() {
    List l;
    List r;
		r.pushFront(3);
		TS_ASSERT(l.containsAll(r) == false);
  }
	
  void testContainsAll3() {
    List l;
		l.pushFront(2);
    List r;
		r.pushFront(3);
		TS_ASSERT(l.containsAll(r) == false);
  }
	
  void testContainsAll4() {
    List l;
		l.pushFront(3);
    List r;
		r.pushFront(3);
		r.pushFront(5);
		TS_ASSERT(l.containsAll(r) == false);
  }
	
  void testPopFrontEmpty() {
    List l;
		TS_ASSERT(l.popFront() == 0);
  }
	
  void testPopFront1() {
    List l;
		l.pushFront(5);
		TS_ASSERT(l.size() == 1);
		TS_ASSERT(l.popFront() == 5);
		TS_ASSERT(l.size() == 0);
  }
	
  void testPopFront2() {
    List l;
		l.pushFront(5);
		l.pushFront(6);
		TS_ASSERT(l.size() == 2);
		TS_ASSERT(l.popFront() == 6);
		TS_ASSERT(l.size() == 1);
		TS_ASSERT(l.popFront() == 5);
		TS_ASSERT(l.size() == 0);
		TS_ASSERT(l.popFront() == 0);
  }
	
  void testPopEndEmpty() {
    List l;
		TS_ASSERT(l.popEnd() == 0);
  }
	
  void testPopEnd1() {
    List l;
		l.pushFront(5);
		TS_ASSERT(l.size() == 1);
		TS_ASSERT(l.popEnd() == 5);
		TS_ASSERT(l.size() == 0);
  }
	
  void testPopEnd2() {
    List l;
		l.pushFront(5);
		l.pushFront(6);
		TS_ASSERT(l.size() == 2);
		TS_ASSERT(l.popEnd() == 5);
		TS_ASSERT(l.size() == 1);
		TS_ASSERT(l.popEnd() == 6);
		TS_ASSERT(l.size() == 0);
		TS_ASSERT(l.popEnd() == 0);
  }
	
  void testSetNPos() {
    List l;
		l.pushFront(6);
		l.pushFront(5);
		l.pushFront(4);
		l.pushFront(3);
		l.pushFront(2);
		l.pushFront(1);
		l.pushFront(0);
		TS_ASSERT(l.setNth(2, 20));
		TS_ASSERT(l.setNth(0, 10));
		TS_ASSERT(! l.setNth(8, 55));
		TS_ASSERT(l.at(0) == 10);
		TS_ASSERT(l.at(1) == 1);
		TS_ASSERT(l.at(2) == 20);
		TS_ASSERT(l.at(3) == 3);
		TS_ASSERT(l.at(4) == 4);
		TS_ASSERT(l.size() == 7);
  }
	
  void testSetNNeg() {
    List l;
		l.pushFront(6);
		l.pushFront(5);
		l.pushFront(4);
		l.pushFront(3);
		l.pushFront(2);
		l.pushFront(1);
		l.pushFront(0);
		TS_ASSERT(l.setNth(-3, 20));
		TS_ASSERT(l.setNth(-1, 10));
		TS_ASSERT(! l.setNth(-8, 55));
		TS_ASSERT(l.at(0) == 0);
		TS_ASSERT(l.at(1) == 1);
		TS_ASSERT(l.at(2) == 2);
		TS_ASSERT(l.at(3) == 3);
		TS_ASSERT(l.at(4) == 20);
		TS_ASSERT(l.at(5) == 5);
		TS_ASSERT(l.at(6) == 10);
		TS_ASSERT(l.size() == 7);
  }
	
	void testInsertPosEmpty(){
		List l;
		TS_ASSERT(! l.insertNth(0,5));
	}
	
  void testInsertPos() {
    List l;
		l.pushFront(6);
		l.pushFront(5);
		l.pushFront(4);
		l.pushFront(3);
		l.pushFront(2);
		l.pushFront(1);
		l.pushFront(0);
		TS_ASSERT(l.insertNth(3, 20));	// Order matters!
		TS_ASSERT(l.insertNth(0, 10));
		TS_ASSERT(! l.insertNth(-10, 55));
		TS_ASSERT(l.at(0) == 10);
		TS_ASSERT(l.at(1) == 0);
		TS_ASSERT(l.at(2) == 1);
		TS_ASSERT(l.at(3) == 2);
		TS_ASSERT(l.at(4) == 20);
		TS_ASSERT(l.at(5) == 3);
		TS_ASSERT(l.at(6) == 4);
		TS_ASSERT(l.size() == 9);
  }
	
  void testInsertNeg() {
    List l;
		l.pushFront(6);
		l.pushFront(5);
		l.pushFront(4);
		l.pushFront(3);
		l.pushFront(2);
		l.pushFront(1);
		l.pushFront(0);
		TS_ASSERT(l.insertNth(-3, 20));	// Order matters!
		TS_ASSERT(l.insertNth(0, 10));
		TS_ASSERT(! l.insertNth(-10, 55));
		TS_ASSERT(l.at(0) == 10);
		TS_ASSERT(l.at(1) == 0);
		TS_ASSERT(l.at(2) == 1);
		TS_ASSERT(l.at(3) == 2);
		TS_ASSERT(l.at(4) == 3);
		TS_ASSERT(l.at(5) == 20);
		TS_ASSERT(l.at(6) == 4);
		TS_ASSERT(l.size() == 9);
  }
	
	void testDeleteEmpty(){
		List l;
		TS_ASSERT( l.deleteNth(0) == 0);
	}
	
  void testDeletePos() {
    List l;
		l.pushFront(6);
		l.pushFront(5);
		l.pushFront(4);
		l.pushFront(3);
		l.pushFront(2);
		l.pushFront(1);
		l.pushFront(0);
		TS_ASSERT(l.deleteNth(3) == 3);	// Order matters!
		TS_ASSERT(l.deleteNth(0) == 0);
		TS_ASSERT( l.deleteNth(-10) == 0);
		TS_ASSERT(l.at(0) == 1);
		TS_ASSERT(l.at(1) == 2);
		TS_ASSERT(l.at(2) == 4);
		TS_ASSERT(l.at(3) == 5);
		TS_ASSERT(l.size() == 5);
  }
	
	void testAppendNone(){
		List l;
		l.pushFront(0);
		List m;
		l.append(m);
		TS_ASSERT(l.size() == 1);
	}
	
	void testAppendSome1(){
		List l;
		l.pushFront(0);
		List m;
		m.pushFront(2);
		m.pushFront(1);
		l.append(m);
		TS_ASSERT(l.size() == 3);
		TS_ASSERT(l.at(0) == 0);
		TS_ASSERT(l.at(1) == 1);
		TS_ASSERT(l.at(2) == 2);
	}
	
	void testAppendSomeShallowTest(){
		List l;
		l.pushFront(0);
		List m;
		m.pushFront(2);
		m.pushFront(1);
		l.append(m);
		TS_ASSERT(l.size() == 3);
		TS_ASSERT(l.at(0) == 0);
		TS_ASSERT(l.at(1) == 1);
		TS_ASSERT(l.at(2) == 2);
		m.pushFront(5);
		TS_ASSERT(l.size() == 3);
	}
	
	void testMesh1Side(){
		List l;
		l.pushFront(1);
		l.pushFront(0);
		List m;
		List n = l.mesh(m);
		TS_ASSERT(n.size() == 2);
		TS_ASSERT(n.at(0) == 0);
		TS_ASSERT(n.at(1) == 1);
		TS_ASSERT(n.at(2) == 0);
	}
	
	void testMesh1Side2(){
		List l;
		l.pushFront(1);
		l.pushFront(0);
		List m;
		List n = m.mesh(l);
		TS_ASSERT(n.size() == 2);
		TS_ASSERT(n.at(0) == 0);
		TS_ASSERT(n.at(1) == 1);
		TS_ASSERT(n.at(2) == 0);
	}
	
	void testMesh2(){
		List l;
		l.pushFront(1);
		l.pushFront(0);
		List m;
		m.pushFront(2);
		m.pushFront(3);
		List n = m.mesh(l);
		TS_ASSERT(n.size() == 4);
		TS_ASSERT(l.size() == 2);
		TS_ASSERT(m.size() == 2);
		TS_ASSERT(n.at(0) == 3);
		TS_ASSERT(n.at(1) == 0);
		TS_ASSERT(n.at(2) == 2);
		TS_ASSERT(n.at(3) == 1);
		TS_ASSERT(n.at(4) == 0);
	}
	
	void testMesh3(){
		List l;
		l.pushFront(1);
		l.pushFront(0);
		List m;
		m.pushFront(2);
		m.pushFront(3);
		m.pushFront(4);
		m.pushFront(5);
		List n = m.mesh(l);
		TS_ASSERT(n.size() == 6);
		TS_ASSERT(l.size() == 2);
		TS_ASSERT(m.size() == 4);
		TS_ASSERT(n.at(0) == 5);
		TS_ASSERT(n.at(1) == 0);
		TS_ASSERT(n.at(2) == 4);
		TS_ASSERT(n.at(3) == 1);
		TS_ASSERT(n.at(4) == 3);
		TS_ASSERT(n.at(5) == 2);
	}
	
	void testMesh4(){
		List m;
		m.pushFront(1);
		m.pushFront(0);
		List l;
		l.pushFront(2);
		l.pushFront(3);
		l.pushFront(4);
		l.pushFront(5);
		List n = m.mesh(l);
		TS_ASSERT(n.size() == 6);
		TS_ASSERT(l.size() == 4);
		TS_ASSERT(m.size() == 2);
		TS_ASSERT(n.at(0) == 0);
		TS_ASSERT(n.at(1) == 5);
		TS_ASSERT(n.at(2) == 1);
		TS_ASSERT(n.at(3) == 4);
		TS_ASSERT(n.at(4) == 3);
		TS_ASSERT(n.at(5) == 2);
	}
	
	void testMeshLarge(){
		List m(10000,5);
		List n(10000,6);
		List o = m.mesh(n);
		TS_ASSERT(o.size() == 20000);
		TS_ASSERT(o.at(40) == 5);
		TS_ASSERT(o.at(81) == 6);
	}
	
	void ttestFuzz(){ // This test tries random actions, but unfortunatly random does not always return
		List l(1000,5); // the same sequence from machine to machine.  Thus, print the sum and then change the
		int length = 1000;  // sum check at the end.
		srand(100);
		int next = 1;
		for(int i = 0; i < 100000; i++){
			int action = rand() % 7;
			if(action == 0){
				l.pushEnd(next);
				length++;
			}else if(action == 1){
				l.pushFront(next);
				length++;
			}else if(action == 2){
				l.popEnd();
				length--;
			}else if(action == 3){
				l.popFront();
				length--;
			}else if(action == 4){
				l.setNth((rand() % (length * 2)) - length, next);
			}else if(action == 5){
				l.insertNth(rand() % length, next);
				length++;
			}else{
				l.deleteNth((rand() % (length * 2)) - length);
				length--;
			}
			next++;
			TS_ASSERT(l.size() == length);
		}
		// Find sum.
		unsigned long sum = 0;
		for(int i = 0; i < l.size(); i++){
			sum = sum + l.at(i) * i;
		}
		//TS_ASSERT(sum == 66633603235);  // On OSX
		TS_ASSERT(sum == 4106100497);     // On Linux/Fedora19
		//cout << "sum: " << sum << endl;
	}
	 
};

#endif
