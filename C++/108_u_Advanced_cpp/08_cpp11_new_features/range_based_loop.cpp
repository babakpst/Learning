
// Babak Poursartip
// 09/08/2020

// range based loop
// Udemy: Advanced c++

#include <iostream>
#include <vector>

using namespace std;

//====================================================
int main() {
  puts(" starts \n");
  cout << "\n1-----\n";
  // this is char
  auto txt = {"one", "two", "three"};

  for (auto t : txt)
    cout << t << endl;

  vector<int> num;
  num.push_back(1);
  num.push_back(10);
  num.push_back(11);
  num.push_back(15);
  num.push_back(18);

  for (auto t : num)
    cout << t << endl;

  string hello = "hello";
  for (auto t : hello)
    cout << t << endl;
  puts(" \n ends");

  return 0;
}
