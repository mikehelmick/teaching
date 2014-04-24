#include <iostream>
#include <string>
using namespace std;

class Book {
private:
	int numPages;
	string author;
	string title;
  
public:
	Book(string t, string a, int np) {
		title = t;
		author = a;
		numPages = np;	
	}

	int getNumPages() { 
		return numPages; 
	}
	
	static bool isaLotOfPages(int numPages) { 
		return numPages > 300; 
	}
	
	double printingCost(int bookCopies) {
		return numPages * 0.05 * bookCopies;
	}

	static void mystery(Book &b1, Book &b2, int max) {
		bool bigBook = b1.isaLotOfPages();	// ERROR	OK
		double cost = Book.printingCost(max);	// ERROR	OK
		b1.numPages = b2.getNumPages();		// ERROR	OK
		b1.numPages = this.numPages;			// ERROR	OK
	}
};

int main(int argc, char* argv[]) {
  Book b1("Starting out with C++", "Tony Gaddis", 997);
  Book b2("Jumping into C++", "Alex Allain", 536);

  Book::mystery(b1, b2, 33);

  return 0;
}