
#include <iostream>

float *tax4;

int main() {

  std::cout << "this is inside the code"
            << "\n";

  int pp = 10;
  int *p1;

  p1 = &pp;

  std::cout << " here is the pointer: " << p1 << "\n";
  std::cout << " here is value the pointer is pointing: " << *p1 << "\n";

  p1++;

  std::cout << " here is the pointer: " << p1 << "\n";
  std::cout << " here is value the pointer is pointing: " << *p1 << "\n";
  std::cout << " ====================== "
            << "\n";

  // =========
  float mintax = 12.0f;
  float *tax = &mintax;

  std::cout << " here is the pointer: " << tax << "\n";
  std::cout << " here is value the pointer is pointing: " << *tax << "\n";
  *tax += 0.1 * mintax;
  std::cout << " here is value the pointer is pointing: " << *tax << "\n";
  std::cout << " ====================== "
            << "\n";

  //======
  float *tax2;
  *tax2 = 6325.1;
  std::cout << " here is value the pointer is pointing: " << *tax2 << "\n";
  *tax2 += 0.1 * mintax;
  std::cout << " here is value the pointer is pointing: " << *tax2 << "\n";
  std::cout << " ====================== "
            << "\n";

  //======
  float value = 0.0f;
  tax4 = &value;
  std::cout << " tax4: here is value the pointer is pointing: " << *tax4
            << "\n";
  // value += 0.1 * mintax;
  *tax4 += 0.1 * mintax;
  std::cout << " tax4: here is value the pointer is pointing: " << *tax4
            << "\n";
  std::cout << " ====================== "
            << "\n";

  //    ======
  const int i = 9;
  const int *p11 = &i; // data is const, not the pointer

  std::cout << " here is the pointer: " << p11 << "\n";
  std::cout << " here is the value of the pointer: " << *p11 << "\n";
  p11++;
  std::cout << " here is the pointer: " << *p11 << "\n";

  // int* const p2; // pointer is const, not the data
  // const int* const p3; // pointer and the data is const

  // if const is on the left of *, data is const
  // if const is on the right of *, pointer is const

  // These are equivalent: const int *p = &i   ====== int const *p=&i

  return 0;
}
