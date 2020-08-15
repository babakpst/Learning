
// Babak Poursartip
// 08/14/2020

// the credit goes to the linkedin course stl
#include <iostream>
#include <list>

// This will print the content of the list
void print(const std::list<int> &myVec) {

  printf(" The list is [ ");
  for (const int &num : myVec) {
    printf(" %d ", num);
  }
  printf(" ]\n ");
}

int main() {

  puts(" \n code starts ... ");

  std::list<int> num;
  int value = 0;

  // push back the list
  puts(" pusing back ...");
  while (value >= 0) {
    printf(" enter a number: ");
    std::cin >> value;
    if (value >= 0)
      num.push_back(value); // pushes elements to the end of the list
  }
  print(num);

  value = 0;
  // push back the list
  puts(" pusing front ...");
  while (value >= 0) {
    printf(" enter a number: ");
    std::cin >> value;
    if (value >= 0) {
      // pushes elements to the beginning of the list (or any other location)
      num.push_front(value);
      // num.insert(num.begin(), value); // equivalent to the previous line
    }
  }
  print(num);

  puts(" \n Terminates successfully. ");

  return 0;
}