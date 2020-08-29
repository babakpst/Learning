
// Babak Poursartip
// 08/29/2020

// STL
// Udemy: Advanced c++

// Set holds unique elements

#include <iostream>
#include <set>

using namespace std;

// using class in a set
class myTest {
private:
  int _id;
  string _name;

public:
  // myTest() : _id{0}, _name{""} {} // default ctor, but it is not needed
  myTest(int _id, string _name) : _id{_id}, _name{_name} {}
  void print() const { cout << _id << ": " << _name << endl; }
  bool operator<(const myTest &rhs) const { return (_name < rhs._name); }
};

int main() {
  puts(" starts \n");

  set<int> nums;

  nums.insert(10);
  nums.insert(11);
  nums.insert(12);
  nums.insert(13);
  nums.insert(13);

  cout << " ------------------- \n";
  for (set<int>::iterator it = nums.begin(); it != nums.end(); ++it)
    cout << *it << " ";
  cout << endl;

  cout << " ------------------- \n";
  for (auto c : nums)
    cout << c << " ";
  cout << endl;

  cout << " ------------------- \n";
  set<int>::iterator itFind = nums.find(122);

  if (itFind != nums.end())
    cout << " Found: " << *itFind << endl;

  if (nums.count(12))
    cout << " number found.\n";

  cout << " ------------------- \n";
  set<myTest> tests;
  tests.insert(myTest(10, "Bob"));
  tests.insert(myTest(38, "Babak"));
  tests.insert(myTest(39, "Babak")); // won't be inserted bcs it is not unique.
  tests.insert(myTest(35, "Shiva"));
  tests.insert(myTest(33, "Behnaz"));

  for (auto c : tests)
    c.print();

  puts(" \n ends");

  return 0;
}
