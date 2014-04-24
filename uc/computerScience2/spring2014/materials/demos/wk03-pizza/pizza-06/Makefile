
SOURCES = main.cpp topping.cpp pizza.cpp
HEADERS = topping.h pizza.h
TESTS = topping_test.h
OBJECTS = main.o topping.o pizza.o
TEST_OBJECTS = topping.o pizza.o
CC  = g++

CXXTESTGEN = ../../../CxxTest/bin/cxxtestgen

FLAGS   = -Iinclude

a.out: $(OBJECTS)
	g++ $(OBJECTS)

test: testrunner
	./testrunner

testrunner: testrunner.cpp $(TEST_OBJECTS)
	g++ -I. -I../../../CxxTest/ -o testrunner $(TEST_OBJECTS) testrunner.cpp

testrunner.cpp: $(HEADERS) $(SOURCES) $(TESTS)
	$(CXXTESTGEN) --error-printer -o testrunner.cpp $(TESTS)

%.o: %.cpp $(HEADERS)
	g++ -I. -c -o $@ $<

clean:
	rm $(OBJECTS) a.out testrunner.cpp testrunner

