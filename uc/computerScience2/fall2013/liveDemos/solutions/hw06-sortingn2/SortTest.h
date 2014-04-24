#ifndef SORT_TEST_H
#define SORT_TEST_H

#include "Sort.h"

#include <iostream>
#include <cxxtest/TestSuite.h>

using namespace std;

class SortTest : public CxxTest::TestSuite {
public:
  void testisSortedEmpty() {
    vector<int> v;
		Sort s;
		TS_ASSERT(s.isSorted(v));
  }
	
  void testisSorted1() {
    vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		Sort s;
		TS_ASSERT(s.isSorted(v));
  }
	
  void testisSorted2() {
    vector<int> v;
		v.push_back(2);
		v.push_back(1);
		Sort s;
		TS_ASSERT(! s.isSorted(v));
  }
	
  void testisSorted3() {
    vector<int> v;
		v.push_back(2);
		v.push_back(2);
		Sort s;
		TS_ASSERT(s.isSorted(v));
  }
	
  void testisSorted4() {
    vector<int> v;
		v.push_back(1);
		v.push_back(3);
		v.push_back(2);
		v.push_back(4);
		Sort s;
		TS_ASSERT(! s.isSorted(v));
  }
/*************************************************/	
	void testSelectionSort0(){
    vector<int> v;
		Sort s;
		vector<int> result = s.selectionSort(v);
		TS_ASSERT(s.isSorted(result));
	}
	
	void testSelectionSort1(){
    vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		Sort s;
		vector<int> result = s.selectionSort(v);
		TS_ASSERT(s.isSorted(result));
	}
	
	void testSelectionSort2(){
    vector<int> v;
		v.push_back(4);
		v.push_back(3);
		v.push_back(2);
		v.push_back(1);
		Sort s;
		vector<int> result = s.selectionSort(v);
		TS_ASSERT(s.isSorted(result));
	}
	
	void testSelectionSort3(){
    vector<int> v;
		v.push_back(1);
		Sort s;
		vector<int> result = s.selectionSort(v);
		TS_ASSERT(s.isSorted(result));
	}
	
	void testSelectionSort4(){
    vector<int> v;
		v.push_back(1);
		v.push_back(3);
		v.push_back(2);
		v.push_back(4);
		Sort s;
		vector<int> result = s.selectionSort(v);
		TS_ASSERT(s.isSorted(result));
	}
/*************************************************/	
  void testGnomeSort0(){
    vector<int> v;
		Sort s;
		vector<int> result = s.gnomeSort(v);
		TS_ASSERT(s.isSorted(result));
	}
	
	void testGnomeSort1(){
    vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		Sort s;
		vector<int> result = s.gnomeSort(v);
		TS_ASSERT(s.isSorted(result));
	}
	
	void testGnomeSort2(){
    vector<int> v;
		v.push_back(4);
		v.push_back(3);
		v.push_back(2);
		v.push_back(1);
		Sort s;
		vector<int> result = s.gnomeSort(v);
		TS_ASSERT(s.isSorted(result));
	}
	
	void testGnomeSort3(){
    vector<int> v;
		v.push_back(1);
		Sort s;
		vector<int> result = s.gnomeSort(v);
		TS_ASSERT(s.isSorted(result));
	}
	
	void testGnomeSort4(){
    vector<int> v;
		v.push_back(1);
		v.push_back(3);
		v.push_back(2);
		v.push_back(4);
		Sort s;
		vector<int> result = s.gnomeSort(v);
		TS_ASSERT(s.isSorted(result));
	}
/*************************************************/	
  void testShellSort0(){
    vector<int> v;
		Sort s;
		vector<int> result = s.shellSort(v);
		TS_ASSERT(s.isSorted(result));
	}
	
	void testShellSort1(){
    vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		Sort s;
		vector<int> result = s.shellSort(v);
		TS_ASSERT(s.isSorted(result));
	}
	
	void testShellSort2(){
    vector<int> v;
		v.push_back(4);
		v.push_back(3);
		v.push_back(2);
		v.push_back(1);
		Sort s;
		vector<int> result = s.shellSort(v);
		TS_ASSERT(s.isSorted(result));
	}
	
	void testShellSort3(){
    vector<int> v;
		v.push_back(1);
		Sort s;
		vector<int> result = s.shellSort(v);
		TS_ASSERT(s.isSorted(result));
	}
	
	void testShellSort4(){
    vector<int> v;
		v.push_back(1);
		v.push_back(3);
		v.push_back(2);
		v.push_back(4);
		Sort s;
		vector<int> result = s.shellSort(v);
		TS_ASSERT(s.isSorted(result));
	}
/*************************************************/	
  void testyourBestSort0(){
    vector<int> v;
		Sort s;
		vector<int> result = s.yourBestSort(v);
		TS_ASSERT(s.isSorted(result));
	}
	
	void testYourBestSort1(){
    vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		Sort s;
		vector<int> result = s.yourBestSort(v);
		TS_ASSERT(s.isSorted(result));
	}
	
	void testYourBestSort2(){
    vector<int> v;
		v.push_back(4);
		v.push_back(3);
		v.push_back(2);
		v.push_back(1);
		Sort s;
		vector<int> result = s.yourBestSort(v);
		TS_ASSERT(s.isSorted(result));
	}
	
	void testYourBestSort3(){
    vector<int> v;
		v.push_back(1);
		Sort s;
		vector<int> result = s.yourBestSort(v);
		TS_ASSERT(s.isSorted(result));
	}
	
	void testYourBestSort4(){
    vector<int> v;
		v.push_back(1);
		v.push_back(3);
		v.push_back(2);
		v.push_back(4);
		Sort s;
		vector<int> result = s.yourBestSort(v);
		TS_ASSERT(s.isSorted(result));
	}

  
};

#endif