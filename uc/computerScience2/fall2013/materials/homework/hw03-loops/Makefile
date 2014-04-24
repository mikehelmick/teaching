CC=g++
CFLAGS=-Wall -I. -g
LDFLAGS=
EXECUTABLE=a.out

OBJECTS=$(SOURCES:.cpp=.o)
OBJECTSTEST=bigint.o

FLAGS   = -I.

grid: clean grid.cpp
	$(CC) $(CFLAGS) grid.cpp

helmick-grid: clean helmick-grid.cpp
	$(CC) $(CCFLAGS) helmick-grid.cpp

spiral: clean spiral.cpp
	$(CC) $(CFLAGS) spiral.cpp

clean:
	-rm a.out
