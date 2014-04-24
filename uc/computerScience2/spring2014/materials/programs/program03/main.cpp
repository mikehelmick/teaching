/*
 * main.cpp
 * Name: helmick
 *
 * Test driver for LL program.
 *
 */

#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <string>
#include <sstream>

using namespace std;

#include <List.h>
#include <Stack.h>
#include <Queue.h>

class Foo {
private:
  int fooNum;
  static int fooCounter;
public:
  Foo() {
    fooNum = ++fooCounter;
  }

  Foo(const Foo &other) {
    this->fooNum = other.fooNum;
  }

  int getFooNum() const {
    return fooNum;
  }

  bool operator==(const Foo &rhs) {
    return this->fooNum == rhs.fooNum;
  }

  bool operator!=(const Foo &rhs) {
    return this->fooNum != rhs.fooNum;
  }
};
int Foo::fooCounter = 0;

std::ostream& operator<<(std::ostream& os, const Foo &obj) {
  os << "foo: " << obj.getFooNum();
  return os;
}

template <typename T> void checkValue(T expected, T actual, string message = "") {
  if (!(expected == actual)) {
    stringstream ss;
    ss << "Value mismsatch error, expected '" << expected
      << "' but got '" << actual << "'";
    if (message != "") {
      ss << " message: " << message;
    }
    throw logic_error(ss.str());
  }
}

void testOne() {
  cout << "Testing basic list creation" << endl;

  List<int>* list = new List<int>();
  list->pushEnd(1);
  list->pushEnd(2);
  list->pushEnd(3);
  list->print();

  checkValue(1, list->at(0));
  checkValue(2, list->at(1));
  checkValue(3, list->at(2));

  delete list;
}

void testTwo() {
  cout << "Creating a large list" << endl;
  List<int>* list = new List<int>();
  for (int i = 0; i < 10000; i++) {
    checkValue(i, list->size());
    list->pushEnd(i);
    checkValue(i + 1, list->size());
  }
  // verify
  for (int i = 0; i < 10000; i++) {
    checkValue(i, list->at(i));
  }
  delete list;
}

void testThree() {
  cout << "testing pushFront" << endl;

  List<int>* list = new List<int>();
  list->pushFront(42);
  checkValue(1, list->size());
  checkValue(42, list->at(0));

  list->pushEnd(43);
  checkValue(2, list->size());
  checkValue(42, list->at(0));
  checkValue(43, list->at(1));

  list->pushFront(41);
  checkValue(3, list->size());
  checkValue(41, list->at(0));
  checkValue(42, list->at(1));
  checkValue(43, list->at(2));

  delete list;
}

void testFour() {
  cout << "Test contains" << endl;

  List<string>* list = new List<string>();
  for (int i = 0; i < 100; i++) {
    stringstream ss;
    ss << i;
    list->pushEnd(ss.str());
  }
  checkValue(100, list->size());

  for (int i = 0; i < 100; i++) {
    stringstream ss;
    ss << i;
    checkValue(true, list->contains(ss.str()));
  }
  checkValue(false, list->contains("whatever"));
  checkValue(false, list->contains("one"));

  delete list;
}

void testFive() {
  cout << "Test contains all" << endl;

  List<int>* l1 = new List<int>();
  l1->pushEnd(1);
  l1->pushEnd(2);
  l1->pushEnd(3);
  l1->pushEnd(4);

  List<int>* l2 = new List<int>();
  l2->pushEnd(2);
  l2->pushEnd(3);

  checkValue(true, l1->containsAll(*l2));
  delete l1;
  delete l2;
}

void testSix() {
  cout << "Test contains all" << endl;

  List<int>* l1 = new List<int>();
  l1->pushEnd(1);
  l1->pushEnd(2);
  l1->pushEnd(3);
  l1->pushEnd(4);

  List<int>* l2 = new List<int>();
  l2->pushEnd(2);
  l2->pushEnd(3);
  l2->pushEnd(15);

  checkValue(false, l1->containsAll(*l2));
  delete l1;
  delete l2;
}

void testSeven() {
  cout << "Test popFront" << endl;

  List<Foo>* ll = new List<Foo>();

  for (int i = 0; i < 100; i++) {
    Foo f;
    ll->pushEnd(f);
  }

  for (int i = 0; i < 100; i++) {
    Foo f = ll->popFront();
    checkValue(i + 1, f.getFooNum());
  }

  delete ll;
}

void testEight() {
  cout << "Test popEnd" << endl;

  List<Foo>* ll = new List<Foo>();

  for (int i = 0; i < 100; i++) {
    Foo f;
    ll->pushFront(f);
  }

  for (int i = 0; i < 100; i++) {
    Foo f = ll->popEnd();
    checkValue(i + 1, f.getFooNum());
  }

  delete ll;
}

void testNine() {
  cout << "test exceptions" << endl;

  List<Foo>* ll = new List<Foo>();

  try {
    ll->popEnd();
    checkValue(true, false, string("failed to throw length error"));
  } catch (length_error &e) {
  }

  try {
    ll->popFront();
    checkValue(true, false, string("failed to throw length error"));
  } catch (length_error &e) {
  }
}

void testTen() {
  cout << "test setNth" << endl;

  Foo f;
  List<Foo>* ll = new List<Foo>();
  for (int i = 0; i < 100; i++) {
    Foo foo;
    ll->pushEnd(foo);
  }
  for (int i = 0; i < 100; i++) {
    ll->setNth(i, f);
  }

  for (int i = 0; i < 100; i++) {
    checkValue(f, ll->at(i));
  }
  delete ll;
}

void testEvelen() {
  cout << "test setNth negative" << endl;

  Foo f;
  List<Foo>* ll = new List<Foo>();
  for (int i = 0; i < 100; i++) {
    Foo foo;
    ll->pushEnd(foo);
  }
  for (int i = 0; i < 100; i++) {
    if (i % 2 == 1) {
      ll->setNth(i * -1, f);
    }
  }

  for (int i = 0; i < 100; i++) {
    if (i % 2 == 1) {
      checkValue(f, ll->at(i * -1));
    } else {
      checkValue(true, f != ll->at(i * -1));
    }
  }
  delete ll;
}

void testTwelve() {
  cout << "test insertNth" << endl;

  List<int>* ll = new List<int>();
  for (int i = 0; i < 5; i++) {
    ll->pushEnd(1);
  }
  // 1 1 1 1 1
  ll->insertNth(1, 2);
  // 1 2 1 1 1 1
  ll->insertNth(3, 2);
  // 1 2 1 2 1 1 1
  ll->insertNth(5, 2);
  // 1 2 1 2 1 2 1 1
  ll->insertNth(7, 2);
  // 1 2 1 2 1 2 1 2 1
  ll->insertNth(ll->size(), 2);
  // 1 2 1 2 1 2 1 2 1 2

  int target = 1;
  while (ll->size() != 0) {
    if (target == 1) {
      checkValue(target, ll->popFront());
      target = 2;
    } else {
      checkValue(target, ll->popFront());
      target = 1;
    }
  }
  delete ll;
}

void testThirteen() {
  cout << "test deleteNth" << endl;

  List<int>* ll = new List<int>();
  for (int i = 0; i < 5; i++) {
    ll->pushEnd(i);
  }
  // 0 1 2 3 4
  checkValue(1, ll->deleteNth(1));
  // 0 2 3 4
  checkValue(3, ll->deleteNth(2));
  // 0 2 4
  checkValue(0, ll->deleteNth(0));
  // 2 4
  checkValue(4, ll->deleteNth(1));
  checkValue(2, ll->deleteNth(0));

  delete ll;
}

void testFourteen() {
  cout << "test append " << endl;

  List<Foo>* l1 = new List<Foo>();
  List<Foo>* l2 = new List<Foo>();

  for (int i = 0; i < 10; i++) {
    Foo f;
    l1->pushEnd(f);
  }
  for (int i = 0; i < 10; i++) {
    Foo f;
    l2->pushEnd(f);
  }

  l1->append(*l2);
  checkValue(20, l1->size());
  for (int i = 0; i < 20; i++) {
    checkValue(i + 1, l1->at(i).getFooNum());
  }
}

void testFifteen() {
  cout << "test mesh" << endl;

  List<Foo>* l1 = new List<Foo>();
  List<Foo>* l2 = new List<Foo>();

  for (int i = 0; i < 10; i++) {
    Foo f1;
    l1->pushEnd(f1);
    Foo f2;
    l2->pushEnd(f2);
  }
  {
    Foo f;
    l2->pushEnd(f);
  }

  List<Foo> meshed = l1->mesh(*l2);
  checkValue(21, meshed.size());
  for (int i = 1; i <= 21; i++) {
    Foo f = meshed.popFront();
    checkValue(i, f.getFooNum());
  }
  delete l1;
  delete l2;
}

int main(int argc, char* argv[]){
	if (argc != 2) {
    cout << "Must pass test case #" << endl;
    return -1;
  }

  int testNum = atoi(argv[1]);
  switch (testNum) {
    case 1: testOne(); break;
    case 2: testTwo(); break;
    case 3: testThree(); break;
    case 4: testFour(); break;
    case 5: testFive(); break;
    case 6: testSix(); break;
    case 7: testSeven(); break;
    case 8: testEight(); break;
    case 9: testNine(); break;
    case 10: testTen(); break;
    case 11: testEvelen(); break;
    case 12: testTwelve(); break;
    case 13: testThirteen(); break;
    case 14: testFourteen(); break;
    case 15: testFifteen(); break;
    default:
      cout << "Invalid test case number." << endl;
      return 1;
  }
  cout << " **passed** " << endl;

	return 0;
}
