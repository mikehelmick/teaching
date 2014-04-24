
SOURCES = main.cpp
HEADERS = topping.h
OBJECTS = main.o
CC  = g++

FLAGS   = -Iinclude

all: $(OBJECTS)

%.o: %.cpp $(HEADERS)
	g++ -I. -c -o $@ $<

