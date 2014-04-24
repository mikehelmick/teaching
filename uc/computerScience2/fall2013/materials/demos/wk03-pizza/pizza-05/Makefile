
SOURCES = main.cpp topping.cpp pizza.cpp
HEADERS = topping.h pizza.h
OBJECTS = main.o topping.o pizza.o
CC  = g++

FLAGS   = -Iinclude

a.out: $(OBJECTS)
	g++ $(OBJECTS)

%.o: %.cpp $(HEADERS)
	g++ -I. -c -o $@ $<

clean:
	rm $(OBJECTS) a.out

