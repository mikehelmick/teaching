#include <iostream>
#include <string>
using namespace std;

void reverseStr(string& str, int s, int e) {
  if (s >= e) {
    return;
  }
  char tmp = str[e];
  str[e] = str[s];
  str[s] = tmp;
  reverseStr(str, s + 1, e - 1);
}

void subReverse(string &str, const string &sub, int start) {
  if (str.size() - start < sub.size()) {
    return;
  }
  bool reverse = true;
  for (int i = 0; i < sub.size(); i++) {
    if (str[start + i] != sub[i]) {
      reverse = false;
      break;
    }    
  }
  if (reverse) {
    reverseStr(str, start, start + sub.size() - 1);
  }
  subReverse(str, sub, start + 1);
}

void subReverse(string &str, const string &sub) {
  subReverse(str, sub, 1);
}

int main() {
  string str = "this is super swish.";
  string sub = "is";
  
  subReverse(str, sub);
  cout << "SubReversed: " << str << endl;
}