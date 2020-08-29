
// Babak Poursartip
// 08/28/2020

// STL
// Udemy: Advanced c++

#include <iostream>
#include <list>
using namespace std;

int main() {
  puts(" starts \n");

  list<int> nums;
  nums.push_back(1);
  nums.push_back(2);
  nums.push_back(3);
  nums.push_front(0);

  list<int>::iterator it = nums.begin();
  it++;
  nums.insert(it, 100);
  cout << " element : " << *it << endl;

  list<int>::iterator eit = nums.begin();
  eit++;
  // since we erased this iterator, we invalidate it. So we cannot use it.
  // nums.erase(eit);
  eit = nums.erase(eit); // This one is fine though.

  cout << " element : " << *eit << endl;

  for (list<int>::iterator it = nums.begin(); it != nums.end(); ++it)
    cout << *it << endl;

  puts(" \n ends");

  return 0;
}
