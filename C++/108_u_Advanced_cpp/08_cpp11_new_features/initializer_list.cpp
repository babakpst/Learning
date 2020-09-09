
// Babak Poursartip
// 09/09/2020

// Udemy: Advanced c++
// initialization list: used in constructor for a class.
// Initializer list: This is different from initialization, and used to
// initialize variables and vectors.

#include <initializer_list> // to be able to use initializer list in a class.
#include <iostream>
#include <vector>

using namespace std;

//====================================================
class test {
public:
  test(initializer_list<string> texts) {
    for (auto c : texts)
      cout << c << endl;
  }
  void print(initializer_list<string> l) {
    cout << "\n this is a print statement with initializer\n";
    for (auto c : l)
      cout << c << endl;
  }
};

//====================================================
int main() {
  cout << " starts \n";
  cout << "\n1-----\n";

  vector<int> nums{1, 2, 4, 5, 6}; // initializer list
  cout << nums[3] << endl;

  test tst{"apple", "banana", "peach"};

  // passing an array to a function, w/o defining an array first.
  tst.print({"one", "two", "three", "four"});

  cout << " \n ends";

  return 0;
}
