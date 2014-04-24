CXXFLAGS =	-O2 -ggdb -Wall -fmessage-length=0 -I.

OBJS =		Bookstore.o Author.o Book.o

LIBS =

TARGET =	Bookstore

$(TARGET):	$(OBJS)
	$(CXX) -o -ggdb $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
