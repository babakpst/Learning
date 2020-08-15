
// Babak Poursartip

// 08/14/2020

// the credit goes to the linkedin course stl
#include <iostream>
#include <vector>

// This will print the content of the vector
void print(const std::vector<int> &myVec) {

  printf(" The vector is [ ");
  for (const int &num : myVec) {
    printf(" %d ", num);
  }
  printf(" ]\n ");
}

int main() {

  puts(" \n code starts ... ");

  std::vector<int> num;
  int value = 0;

  // push back the vector
  puts(" pusing back ...");
  while (value >= 0) {
    printf(" enter a number: ");
    std::cin >> value;
    if (value >= 0)
      num.push_back(value); // pushes elements to the end of the vector
  }
  print(num);

  value = 0;
  // push back the vector
  puts(" pusing front ...");
  while (value >= 0) {
    printf(" enter a number: ");
    std::cin >> value;
    if (value >= 0)
      // pushes elements to the beginning of the vector (or any other location)
      num.insert(num.begin(), value);
  }
  print(num);

  // insert a number in a specific location in the vector
  int index = 0;
  puts(" insert by index ...");
  while (index >= 0) {
    printf(" enter index: ");
    std::cin >> index;
    if (index >= 0) {
      printf(" enter a number: ");
      std::cin >> value;
      // insert a number at the index location
      num.insert(num.begin() + index, value);
    }
  }
  print(num);

  // push back the vector
  index = 0;
  puts(" Modifying an existing element ...");
  while (index >= 0) {
    printf(" enter index: ");
    std::cin >> index;
    if (index >= 0) {
      printf(" enter a number: ");
      std::cin >> value;
      // insert a number at the index location
      num[index] = value;
    }
  }
  print(num);

  puts(" \n Terminates successfully. ");

  return 0;
}