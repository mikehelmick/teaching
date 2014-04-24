
SOURCES = main.cpp topping.cpp pizza.cpp
HEADERS = topping.h pizza.h
OBJECTS = main.o topping.o pizza.o
CC  = g++

CC_FLAGS   = -I. -c

a.out: $(OBJECTS)
	$(CC) $(OBJECTS)

%.o: %.cpp $(HEADERS)
	$(CC) $(CC_FLAGS) -o $@ $<

clean:
	rm $(OBJECTS) a.out

