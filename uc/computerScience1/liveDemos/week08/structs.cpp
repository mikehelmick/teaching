#include <iostream>
#include <string>
using namespace std;

struct Student {
  string name;
  string hometown;
  int gradYear;
  float gpa;
  int credits;
};

void printStudent(Student &s) {
  cout << "    Name: " << s.name << endl;
  cout << "Hometown: " << s.hometown << endl;
  cout << "   Class: " << s.gradYear << endl;
  cout << "     GPA: " << s.gpa << endl;
  cout << " Credits: " << s.credits << endl;
}

int main() {
  cout << "sizeof(int) = " << sizeof(int) << endl;
  cout << "sizeof(string) = " << sizeof(string) << endl;
  cout << "sizeof(float) = " << sizeof(float) << endl;
  cout << " ------ " << endl;
  cout << "sizeof(Student) = " << sizeof(Student) << endl;

  int x = 4;
  Student myRecord;
  myRecord.name = "Susie Student";
  myRecord.hometown = "Cincinnati";
  myRecord.gradYear = 2016;
  myRecord.gpa = 3.94;
  myRecord.credits = 85;
  printStudent(myRecord);

  Student myClass[10];
  for (int i = 0; i < 10; i++) {
    cout << "STUDENT #" << i << endl;
    printStudent(myClass[i]);
  }
}






