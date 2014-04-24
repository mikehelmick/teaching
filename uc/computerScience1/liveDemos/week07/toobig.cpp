
void getArray() {
  int x[10485760];
  for (int i = 0; i < 100; i++) {
    x[i] = 0;
  }
}

int main() {
  getArray();

  return 0;
}
