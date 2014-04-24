/**
 * @author Mike Helmick - mike.helmick@uc.edu
 *
 * Tests for the Dictionary class
 */
#ifndef DICTIONARY_TEST_H
#define DICTIONARY_TEST_H

#include <Dictionary.h>

#include <iostream>
#include <cxxtest/TestSuite.h>

using namespace std;

class DictionaryTest : public CxxTest::TestSuite {
public:
  void testDictionary() {
    Dictionary dict("wordswithfriends.txt");
    TS_ASSERT_EQUALS(168037, dict.getWordCount());
  }
};
  
#endif