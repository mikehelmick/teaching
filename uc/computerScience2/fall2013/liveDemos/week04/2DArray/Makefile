
SOURCES = main.cpp 
HEADERS = 
TESTS = 
OBJECTS = main.o 
TEST_OBJECTS = 
CC  = g++

CXXTESTGEN = ../../CxxTest/bin/cxxtestgen

FLAGS   = -Iinclude

a.out: $(OBJECTS)
	g++ -O3 $(OBJECTS)

test: testrunner
	./testrunner

testrunner: testrunner.cpp $(TEST_OBJECTS)
	g++ -I. -I../../CxxTest/ -o testrunner $(TEST_OBJECTS) testrunner.cpp

testrunner.cpp: $(HEADERS) $(SOURCES) $(TESTS)
	$(CXXTESTGEN) --error-printer -o testrunner.cpp $(TESTS)

%.o: %.cpp $(HEADERS)
	g++ -I. -c -O3 -o $@ $<

clean:
	-rm $(OBJECTS) a.out testrunner.cpp testrunner
