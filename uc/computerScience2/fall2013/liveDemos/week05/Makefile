
CC  = g++
CC_FLAGS = -I. -Wall -g

CXXTESTGEN = ../CxxTest/bin/cxxtestgen

FLAGS   = -Iinclude

initialization: clean initialization.cpp
	$(CC) $(CC_FLAGS) initialization.cpp
	./a.out

lifetime: clean lifetime.cpp
	$(CC) $(CC_FLAGS) lifetime.cpp
	./a.out

leak: clean leak.cpp
	$(CC) $(CC_FLAGS) leak.cpp
	./a.out

doubledelete: clean doubledelete.cpp
	$(CC) $(CC_FLAGS) doubledelete.cpp
	./a.out

copy: clean copy.cpp
	$(CC) $(CC_FLAGS) copy.cpp
	./a.out

copy2: clean copy2.cpp
	$(CC) $(CC_FLAGS) copy2.cpp
	./a.out

assignment: clean assignment.cpp
	$(CC) $(CC_FLAGS) assignment.cpp
	./a.out

test: testrunner
	./testrunner

testrunner: testrunner.cpp $(TEST_OBJECTS)
	g++ -I. -I../../CxxTest/ -o testrunner $(TEST_OBJECTS) testrunner.cpp

testrunner.cpp: $(HEADERS) $(SOURCES) $(TESTS)
	$(CXXTESTGEN) --error-printer -o testrunner.cpp $(TESTS)s

clean:
	-rm a.out
	-rm -r a.out.dSYM

# testrunner.cpp testrunner

