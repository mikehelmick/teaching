
SOURCES = main.cpp topping.cpp pizza.cpp pizza_test.cpp
HEADERS = topping.h pizza.h
TESTS = topping_test.h pizza_test.h
TEST_GCH = topping_test.h.gch pizza_test.h.gch
OBJECTS = main.o topping.o pizza.o pizza_test.o
TEST_OBJECTS = topping.o pizza.o pizza_test.o
CC  = g++

CXXTESTGEN = ../../CxxTest/bin/cxxtestgen

FLAGS   = -Iinclude

a.out: $(OBJECTS)
	g++ -g $(OBJECTS)

test: testrunner
	./testrunner

testrunner: testrunner.cpp $(TEST_OBJECTS) $(TEST_GCH)
	g++ -g -I. -I../../CxxTest/ -o testrunner $(TEST_OBJECTS) testrunner.cpp

testrunner.cpp: $(HEADERS) $(SOURCES) $(TESTS)
	$(CXXTESTGEN) --error-printer -o testrunner.cpp $(TESTS)

%.h.gch: %.h $(TESTS)
	g++ -h -I. -I../../CxxTest/ -c -o $@ $<

%.o: %.cpp $(HEADERS)
	g++ -g -I. -I../../CxxTest/ -c -o $@ $<

clean:
	-rm $(OBJECTS) a.out testrunner.cpp testrunner *.gch

