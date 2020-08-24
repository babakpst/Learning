#include <iostream>

void useAfterDelete(int *p) {
  delete p;
  int j = *p;
}

void do_uninitialized() {
  int j = 42;
  int uninitialized;
  if (uninitialized = uninitialized) {
    std::cout << "Hello" << std::endl;
  }
}

void calcAges() {
  int ages[3];
  ages[1] = 18;
  ages[2] = 21;
  ages[3] = 35;

  int total(0);
  for(auto age: ages){
    total += age;
  }
  std::cout << "Total = " << total << std::endl;
}

int main() {
  useAfterDelete(new int(42));
  do_uninitialized();
  calcAges();
  return 0;
}