#include <iostream>
#include <string>
using namespace std;

class StringWrapper {
public:
  StringWrapper(string &str) {
    data = new string(str);
  }

  StringWrapper(StringWrapper &that) {
    data = new string(*(that.data));
  }

  virtual ~StringWrapper() {
    delete data;
  }

  void append(string &additional) {
    data->append(additional);
  }

  void inspect() {
    cout << "&data: " << &data 
        << " data: " << data
        << " contents: " << *data << endl;
  }

private:
  string* data;
};

int main() {
  string firstStr = "first";
  StringWrapper first(firstStr);
  cout << "Inspecting first: ";
  first.inspect();

  StringWrapper second(first);
  cout << "Inspecting Second: ";
  second.inspect();

  string additional = " append";

  first.append(additional);
  cout << "Inspecting first: ";
  first.inspect();
  cout << "Inspecting Second: ";
  second.inspect();
}