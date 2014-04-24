#include <iostream>
using namespace std;

int main(int argc, const char* argv[]) {
  cout << "# of parameters " << argc << endl;

  for (int i = 0; i < argc; i++) {
    cout << "param " << i << " : " << argv[i] << endl;
  }

  cout << "---" << endl;
  const int my_array_size = 5;
  int my_array[my_array_size] = {2, 4, 6, 8, 10};
  int x = 0;
  for (int i = 0; i < my_array_size; i++) {
    cout << "my_array[" << i << "] = " << my_array[i] << endl;
    x++;
  }

  int array2[5];
  for (int i = 0; i <= 10; i++) {
    cout << "array2[" << i << "] = " << array2[i] << endl;
  }
}
